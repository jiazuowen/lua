function testjaclog(...)
    local f = require "jaclog"
    f.log(123)
    f.logEx("hello Jack")
end

testjaclog()