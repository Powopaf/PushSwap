#!/usr/bin/env lua

local function find_seed()
	local t = os.time()
	local h = math.floor(os.clock() * 1e6)
	local pid = 0
	local p = io.open("/proc/self/stat", "r")
	if p then
		local content = p:read("*n")
		p:close()
		pid = tonumber(content) or 0
	end
	local ur = 0
	local f = io.open("/dev/urandom", "rb")
	if f then
		local bytes = f:read(4)
		f:close()
		if bytes and #bytes == 4 then
			local b1, b2, b3, b4 = bytes:byte(1, 4)
			us = ((b1 * 256 + b2) * 256 + b3) * 256 + b4
		end
	end
	local seed = (t + h + pid + ur + 173) % 2^31
	return seed
end

local size = tonumber(arg[1]) or 100
local min = tonumber(arg[2]) or 0
local max = tonumber(arg[3]) or 1000
local seed = find_seed()
math.randomseed(seed)
for _ = 1, 5 do math.random() end
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