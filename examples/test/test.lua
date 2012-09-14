
-- adjust package.path
package.path = '../../?.lua;' .. package.path

-- load lua0x
require 'lua0x'

-- load module 'test' from libtest.so
lua0x.loadlib('libtest.so', 'test')

-- use module test
test.echo('hi there !')
test.set( 42 )
test.echo('foo: '.. test.get() )

