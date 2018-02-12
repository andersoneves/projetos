function love.load()
  whale = love.graphics.newImage("whale.jpeg")

  i=1
  j=1

end

function love.update(dt)
  j=love.mouse.getY()
  i=love.mouse.getX()
end



function love.draw()
  love.graphics.draw(whale, i, j)
end
