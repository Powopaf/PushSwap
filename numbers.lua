#!/usr/bin/env lua

local size = tonumber(arg[1]) or 100
local min = tonumber(arg[2]) or 0
local max = tonumber(arg[3]) or 1000
math.randomseed(os.time())
if min > max then
	min, max = max, min
end
for i = 1, size do
	io.write(math.random(min, max))
	if i < size then
		io.write(" ")
	end
end
io.write("\n")