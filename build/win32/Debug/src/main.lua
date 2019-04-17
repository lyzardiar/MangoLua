

local function _Update(ctx) 
    if Update then 
        xpcall(function()
            Update(ctx) 
        end, function(msg)
            log(msg)
            log(debug.traceback())
        end)
    end
end

local function Init()
    local backend = require("src.nk.backend")
    backend.init(640, 480, "Mango", true, nil)
end

function Start()
    local backend = require("src.nk.backend")
    require("src.app")
    backend.loop(_Update, {0, 0, 0, 0}, 60)
end

log("Engine Started...")
Init()
