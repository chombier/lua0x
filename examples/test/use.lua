
-- adjust package.path
package.cpath = '../../lib/lib?.so;' .. package.cpath

-- load lua0x
require 'lua0x'

-- load test module
require 'test'

-- use test module 
test.echo('hi there !')
test.set( 42 )
test.echo('foo: '.. test.get() )

