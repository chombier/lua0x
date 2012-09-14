
-- path to lua0x library
local path = 'liblua0x.so'

-- load the library
local load = assert( package.loadlib(path, 'init') )
load()


-- load library @libname defining lua module @module, with @init
-- function as lua entry point
function lua0x.loadlib( libname, module, init )
   init = init or 'init'

   local load = assert( package.loadlib(libname, init) )
   load()
   
   lua0x.load( module )
end
