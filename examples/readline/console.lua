#!/usr/bin/lua

package.cpath = '../../lib/lib?.so;' .. package.cpath

require 'lua0x'
require 'readline'

readline.init()

local str = ''

while str do
	 str = readline.get()
	 print("got:",  str )
end


-- lua0x.load('readline')
-- print 'lol'


