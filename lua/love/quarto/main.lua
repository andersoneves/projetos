function love.load()
  whale = love.graphics.newImage("whale.jpeg")
  bgm = love.audio.newSource("intro.mp3", "stream")
  r=0
  g=0
  b=0
  a=0
  i=1
  j=1
  v=0.5
end

function love.update(dt)
  if love.window.isVisible() ==true then
    love.window.setTitle("Meu Primeiro Joginho")
    love.window.setFullscreen(true,'desktop')
    love.window.maximize()
    width, height = love.graphics.getDimensions()
    love.keyboard.setKeyRepeat(true)

function love.keypressed(key, scancode, isrepeat)
      if key == 'escape' then
        love.event.quit(0)
      end
      if key=='w' and j>0 then
        j=j-5
      end
      if key=='s' and j<height then
        j=j+5
      end
      if key=='a' and i>0 then
        i=i-5
      end
      if key=='d' and i<width then
        i=i+5
      end

      if key=='r' and r<256 then
        r=r+5
      end
      if key=='g' and g<256 then
        g=g+5
      end
      if key=='b' and b<256 then
        b=b+5
      end
      if key=='o' and a<256 then
        a=a+5
      end

      if key=='t' and r>0 then
        r=r-5
      end
      if key=='h' and g>0 then
        g=g-5
      end
      if key=='n' and b>0 then
        b=b-5
      end
      if key=='p' and a>0 then
        a=a-5
      end

      if key=='x' and v>=0 then
        v=v-0.1
      end
      if key=='z' and v<=1 then
        v=v+0.1
      end

    end

 function love.mousemoved(x, y, dx, dy)
   j=y
   i=x
 end

  end

  love.audio.setVolume(v)
  love.audio.play(bgm)
end



function love.draw()
  love.graphics.setBackgroundColor(r, g, b, a)
  love.graphics.draw(whale, i, j)
end
