#!/usr/bin/env perl
use strict;
use warnings;
use Time::HiRes qw(time clock_gettime CLOCK_MONOTONIC);

sub find_seed {
    my $t = time();                              # seconds since epoch (float)
    my $h = int(clock_gettime(CLOCK_MONOTONIC) * 1_000_000); # high-res clock
    my $pid = 0;

    # Read PID from /proc/self/stat (Linux)
    if (open my $p, '<', '/proc/self/stat') {
        my $content = <$p>;
        close $p;
        if (defined $content && $content =~ /^(\d+)/) {
            $pid = $1;
        }
    }

    my $ur = 0;
    # Read 4 bytes from /dev/urandom
    if (open my $f, '<:raw', '/dev/urandom') {
        my $bytes;
        if (read($f, $bytes, 4) == 4) {
            my @b = unpack('C4', $bytes);
            $ur = (($b[0] * 256 + $b[1]) * 256 + $b[2]) * 256 + $b[3];
        }
        close $f;
    }

    my $seed = int(($t + $h + $pid + $ur + 173) % (2**31));
    return $seed;
}

my $size = defined $ARGV[0] ? int($ARGV[0]) : 100;
my $min  = defined $ARGV[1] ? int($ARGV[1]) : 0;
my $max  = defined $ARGV[2] ? int($ARGV[2]) : 1000;

my $seed = find_seed();
srand($seed);

# Discard first few values (like Lua)
rand() for 1..5;

if ($min > $max) {
    ($min, $max) = ($max, $min);
}

for my $i (1 .. $size) {
    my $val = int(rand($max - $min + 1)) + $min;
    print $val;
    print " " if $i < $size;
}
print "\n";
