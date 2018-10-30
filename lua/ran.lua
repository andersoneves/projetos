function mrand(i,f)
	return math.random(i,f);
end

function tableHasKey(table,key)
    return table[key] ~= nil
end

function groups(i)
	groups={};
	math.randomseed(os.time());
	for a=1,i do
		gr='grupo'..a;
		c=mrand(1,i);
		while(tableHasKey(groups,c)~= false)do
			c=mrand(1,i);
		end
		groups[c]=gr;	
	end
	for a=1,i do
		print(a..' > '..groups[a]);
	end
	
end



function list_sort(lista)
	math.randomseed(os.time());
	while(#lista>=1) do
		if #lista > 1 then
			c=mrand(1,#lista);
		else
			c=1;
		end
		print(table.remove(lista,c));
	end
		
end

list={'grupo1','grupo2','grupo3','grupo4','grupo5','grupo6'};
list_sort(list);


function list_match(lista,lista1)
	math.randomseed(os.time());
	table.sort(lista);
	if #lista == #lista1 then
		while(#lista1 >=1) do
			if #lista1 > 1 then
				d=mrand(1,#lista1);
			else
				d=1;
			end
			print(table.remove(lista,1)..' => '..table.remove(lista1,d));
		end
	else
		print('tamanho das listas diferentes');
	end
end

function clean()
	if os.execute("clear") then
		os.execute("clear")
	elseif os.execute("cls") then
    	os.execute("cls");
	else  
    	for i = 1,25 do
        	print("\n")
    	end
	end
end


print(' ');
list={'Grupo 10','Grupo 09','Grupo 08','Grupo 01','Grupo 02','Grupo 03','Grupo 04','Grupo 05','Grupo 06','Grupo 07'};
list1={'Tema A','Tema B','Tema C','Tema D','Tema E','Tema F','Tema G','Tema H','Tema I','Tema J'};
list_match(list,list1);
print(' ');
print(' ');

function criar_trab()
	grupos={};
	temas={};
	op=n;
	repeat	
	  io.write('Entre um Grupo: ');
	  table.insert(grupos, io.read());
	  io.write('Entre um Tema: ');
	  table.insert(temas, io.read());
	  io.write('Deseja inserir mais S/N: ');
	  op=io.read();
	until op~='S' and op~='s'
	clean();
	list_match(grupos,temas);
end

--[[criar_trab();]]--



function criar_grupos(lista,numero)
	for i=1,numero do
		table.insert(lista,'Grupo'..i);
	end

end

lista={};

criar_grupos(lista,10);

for i,v in ipairs(lista) do
	print(v);
end



--[[groups(5);








--]]