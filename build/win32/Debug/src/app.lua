local nk = moonnuklear
print(2)
require("src.nk.demo")

do return end

-- print = function (...)

-- end

local Counter 
Counter = {
    list = {},

    add = function(msg)  
        table.insert(Counter.list, {msg = msg, time = os.clock()})
    end,

    remove = function()
        local len = #Counter.list
        if len > 0 then 
            local info = Counter.list[len]
            table.remove(Counter.list, len)
            print(string.format("%s%s: %.1f", string.rep("\t", len - 1), info.msg, 1.0 / (os.clock() - info.time)))
        end
    end
}

local Start = function() 
    print(3, nk)
end

local op = 'easy'
local value = 0.6
local window_flags = nk.WINDOW_BORDER|nk.WINDOW_MOVABLE|nk.WINDOW_CLOSABLE

local function hellogui(ctx)
   if nk.window_begin(ctx, "Show", {50, 50, 220, 220}, window_flags) then
      -- fixed widget pixel width
      nk.layout_row_static(ctx, 30, 80, 1)

      if nk.button(ctx, nil, "button") then
         -- ... event handling ...
         print("button pressed")
      end

      -- fixed widget window ratio width
      nk.layout_row_dynamic(ctx, 30, 2)
      if nk.option(ctx, 'easy', op == 'easy') then op = 'easy' end
      if nk.option(ctx, 'hard', op == 'hard') then op = 'hard' end

      -- custom widget pixel width
      nk.layout_row_begin(ctx, 'static', 30, 2)
      nk.layout_row_push(ctx, 50)
      nk.label(ctx, "Volume:", nk.TEXT_LEFT)
      nk.layout_row_push(ctx, 110)
      value = nk.slider(ctx, 0, value, 1.0, 0.1)
      nk.layout_row_end(ctx)
   end
   nk.window_end(ctx)
end

Counter.add("Update")
function Update(ctx)
    if Start then Start(); Start = nil; return; end

    Counter.remove()
    Counter.add("Update")

    hellogui(ctx)
end