-- Load some default values for our rectangle.
function love.load()
    x, y, w, h = 50, 20, 20, 20
    a=2
    b=100
    c=20
    cw,cy=0
end

-- Increase the size of the rectangle every frame.
function love.update(dt)


if w < 400 and cw==0 then
    w = w + 1
    if w==399 then
      cw=1
    end
else
    w = w - 1
    if w==0 then
      cw=0
    end

end

if h < 400 and cy==0 then
    h = h + 1
    if h==399 then
      cy=1
    end
else
    h=h-1
    if h==0 then
      cy=0


      a=a+10
      b=b+10
      c=c+10
      if(a>255)then
        a=(a%255)
      end
      if(b>255)then
        b=(b%255)
      end
      if(c>255)then
        c=(c%255)
      end

      x=x+10
      y=y+10
      if x==100 then
        x=0
      end
      if y==100 then
        y=0
      end

    end
end



end

-- Draw a coloured rectangle.
function love.draw()
    love.graphics.setColor(a, b,c)
    love.graphics.rectangle("fill", x, y, w, h)
end
