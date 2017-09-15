x=io.read("*number")
y=io.read("*number")

function fatorial(x)
	if x==1 then
		return 1
	end
	return x*fatorial(x-1)
end

function pw(x,y)
	local a = 1
	for i=1,y do
		a=a*x
	end
	return a
end

function sum (a)
	return function (b) return a+b	end
end

function maior(a,b)
	if a > b then
		return a
	else 
		return b
	end
end

function buble( b )
	local a = b
	for i=1,#a do
		for j=i,#a do
			if(a[i]>a[j])then
				troca(a,i,j)
			end
		end
	end
	return function (x) imprimev(a,x) end
end

function troca(a,i,j)
	local aux
	aux=a[i]
	a[i]=a[j]
	a[j]=aux
end

function imprimev(a,x)
	if(x=="asc")then
			for i=1,#a do
				print("[",a[i],"]")
			end
		else
			for i=#a,1,-1 do
				print("[",a[i],"]")
			end	
		end
end

--comentario

local d={5,3,1,4,2}
local f={5,3,1,4,2,14,32,60,30}
imprimev(d,"asc")
print("==> 1")
b=buble(d)
imprimev(d,"asc")
print("==> 2")
e=buble(f)
b("asc")
print("==> 3")
e("desc")
print("==> 4")

a=sum (x)
print("soma", a(y))
print("soma", a(8))
a=sum(8)

print("soma", a(5))
print("maior", maior("anderson","lucineide"))
print("maior", maior(11,10))
print("maior", maior(11.10,11.12))

print("fatorial",fatorial(x))
print("pow",pw(x,y))
	