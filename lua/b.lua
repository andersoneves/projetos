luasql = require "luasql.mysql"

function connect(banco,usuario,senha,host)
	env = luasql.mysql()	
	con = env:connect(banco,usuario,senha,host)
	return con
end

function iserir(con,tabela,campos,valores )
	cursor,errorString = con:execute("INSERT INTO "..tabela.." ( "..conc(campos)..") VALUES ("..conc(valores)..");")
end

function conc(valores)
	local texto=""
	for i=1,#valores do
		if(i==1)then
			texto=string.format("%s",valores[i])
		else 	
			texto=string.format("%s%s%s",texto,",",valores[i]) 
		end
	end
	return texto
end

local con = connect("test","root","","127.0.0.1")

x=io.read("*number")
y=io.read("*number")

local campos={"t1","t2"}
local tabela = "t1"
local valores={x,y}
iserir(con,tabela,campos,valores)


function SELECT( con,sql )
	local cursor,errorString = con:execute(sql)
	return cursor
end

local cursor=SELECT(con,"SELECT t2 as User,t1 as Password FROM `t1`")

row = cursor:fetch ({}, "a")

while row do
   print(string.format("User: %s, Password: %s", row.User, row.Password))
   row = cursor:fetch (row, "a")
end




cursor:close()
con:close()
env:close()