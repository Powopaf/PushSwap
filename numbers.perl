#!/usr/bin/env perl
use strict;
use warnings;

# numbers.pl
# Usage:
#   ./numbers.pl COUNT MIN MAX
# Example:
#   ./numbers.pl 500 -10000 10000

sub read_4_bytes_entropy {
    my @paths = ("/dev/random", "/dev/urandom"); # fallback if /dev/random blocks/unavailable
    for my $p (@paths) {
        if (open(my $fh, "<:raw", $p)) {
            my $buf = "";
            my $n = read($fh, $buf, 4);
            close($fh);
            if (defined $n && $n == 4) {
                return unpack("N", $buf); # 32-bit unsigned
            }
        }
    }
    return 0; # last resort
}

sub build_seed {
    my $t   = time();     # seconds since epoch
    my $pid = $$;         # current PID
    my $e   = read_4_bytes_entropy(); # first 4 bytes as int

    # User asked "time since epoch + pid + 4 bytes" (numeric addition).
    # Then mix a bit to spread bits better.
    my $seed = ($t + $pid + $e) & 0x7fffffff;
    $seed ^= (($seed << 13) & 0x7fffffff);
    $seed ^= ($seed >> 17);
    $seed ^= (($seed << 5)  & 0x7fffffff);
    return $seed & 0x7fffffff;
}

sub fisher_yates_shuffle {
    my ($arr_ref) = @_;
    for (my $i = $#$arr_ref; $i > 0; $i--) {
        my $j = int(rand($i + 1));
        @$arr_ref[$i, $j] = @$arr_ref[$j, $i];
    }
}

# ---- main ----
my ($count, $min, $max) = @ARGV;

if (!defined $count || !defined $min || !defined $max) {
    die "Usage: $0 COUNT MIN MAX\nExample: $0 10 0 100\n";
}
die "COUNT must be > 0\n" unless $count =~ /^\d+$/ && $count > 0;
die "MIN must be <= MAX\n" if $min > $max;

my $range_size = $max - $min + 1;
die "Range too small: need $count unique numbers but range has only $range_size values\n"
    if $count > $range_size;

my $seed = build_seed();
srand($seed);

# Strategy:
# - If the range isn't huge OR you want a big portion of it -> shuffle the whole range (fast + uniform).
# - Otherwise -> rejection sampling with a hash (memory-friendly for large ranges).
my @out;
if ($range_size <= 5_000_000 || $count > int($range_size / 2)) {
    my @pool = ($min .. $max);
    fisher_yates_shuffle(\@pool);
    @out = @pool[0 .. $count - 1];
} else {
    my %seen;
    while (@out < $count) {
        my $n = $min + int(rand($range_size));
        next if $seen{$n}++;
        push @out, $n;
    }
}

print "$_\n" for @out;
exit 0;