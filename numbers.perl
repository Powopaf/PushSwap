#!/usr/bin/env perl
use strict;
use warnings;

# Check arguments
if (@ARGV != 3) {
    print STDERR "Usage: $0 <size> <min> <max>\n";
    print STDERR "Example: $0 100 -1000 1000\n";
    exit 1;
}

my ($size, $min, $max) = @ARGV;

# Validate arguments
if ($size !~ /^\d+$/ || $size <= 0) {
    print STDERR "Error: size must be a positive integer\n";
    exit 1;
}

if ($min !~ /^-?\d+$/ || $max !~ /^-?\d+$/) {
    print STDERR "Error: min and max must be integers\n";
    exit 1;
}

if ($min >= $max) {
    print STDERR "Error: min must be less than max\n";
    exit 1;
}

# Create a unique seed using time, process ID, and a counter file
# This ensures different seeds even for calls in the same second
my $seed = time() ^ ($$ << 15);

# Add microseconds if Time::HiRes is available
eval {
    require Time::HiRes;
    my $usec = Time::HiRes::time();
    $seed ^= int($usec * 1000000);
};

srand($seed);

# Check if size is larger than the range
my $range = $max - $min + 1;
if ($size > $range) {
    print STDERR "Error: size ($size) cannot be larger than the range ($range)\n";
    exit 1;
}

# Generate unique random numbers using Fisher-Yates shuffle
my @all_numbers = ($min .. $max);
my @numbers;

for (my $i = 0; $i < $size; $i++) {
    my $random_index = int(rand(@all_numbers));
    push @numbers, $all_numbers[$random_index];
    
    # Remove the selected number to avoid duplicates
    splice(@all_numbers, $random_index, 1);
}

# Print numbers space-separated on a single line
print join(' ', @numbers) . "\n";
