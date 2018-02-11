function love.load()
  Message = "Hello from LOVE"
  local secret = 'This is a local string' -- local variable, apostrophes on the string.
end
function love.update(dt)
  Message=string.reverse(Message)
end

function love.draw()
  for i=0,200,20 do
    love.graphics.setColor(255,255, 0, 100)
    love.graphics.print(Message, 200+i, 200+i)
  end
end
