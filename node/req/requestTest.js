var cheerio = require('cheerio');
var request = require('request');
var replaceall = require("replaceall");
var fs = require('fs');
var selecao,opção;
tudo='';
fs.writeFile('tudo.csv','nome\tsituacao\tposicao\tprocessoSeletivo\tcurso\tescolaridade\tcpf \tcidade\testado\tlista\n' , function(err) {
    						if(err) {
      							  return console.log(err);
    						}

    						console.log("The 'tudo.csv' file was cread!" );
						});
request('http://selecao.ifms.edu.br/nomeacoes', function (error, response, body) {
  $=cheerio.load(body);
  //console.log('[['+$('#ps').find('option').length+']]');
  $('#ps').find('option').each(function(i,val){
  	if(i>0){
  			//console.log('||   '+$(this).attr('value')+'  ||');
  			request('http://selecao.ifms.edu.br/ps/'+$(this).attr('value')+'/local/138/opcoes',function(erro,response,data){
          if (error){
                console.log(error);
                return -1;
              }
  				var obj = JSON.parse(data);
  				obj.forEach(function(val,i){
  					//console.log(val.id+'=='+val.processoSeletivo.id);
  					request('http://selecao.ifms.edu.br/nomeacoes/buscar?lista=Ampla%20Concorr%C3%AAncia&opcao='+val.id+'&nome=',function(error, response, data){
  						if (error){
                console.log(error);
                return -1;
              }
              var obj=JSON.parse(data)
  						var strig='';
  						var cab='nome\tsituacao\tposicao\tprocessoSeletivo\tcurso\tescolaridade\tcpf \tcidade\testado\tlista\n';  
  						obj.forEach(function(val,i){
  							strig+=val.inscricao.candidato.nome+'\t'+val.situacao+'\t'+val.posicao+'\t'+val.inscricao.processoSeletivo.alias+'\t'+val.inscricao.cursoPolo.curso.nome+'\t'+val.inscricao.candidato.escolaridade +'\t'+val.inscricao.candidato.cpf +'\t'+val.inscricao.candidato.cidade.nome+'\t'+val.inscricao.candidato.cidade.estado.nome+'\t'+val.lista+'\n';
  							//console.log(val.inscricao.candidato.nome+'\t'+val.situacao+'\t'+val.posicao+'\t'+val.inscricao.processoSeletivo.alias+'\t'+val.inscricao.cursoPolo.curso.nome);	
  						});
  						var nome=val.processoSeletivo.alias+'_'+val.curso.nome+'.csv';
  						nome=replaceall('/','-',nome)
  						nome=replaceall('  ','',nome)
  						nome=replaceall('	','',nome)
  						nome=replaceall(' ','-',nome)
  						nome=replaceall('--','-',nome)
  						nome=replaceall('--','-',nome)
  						fs.writeFile(nome, cab+strig, function(err) {
    						if(err) {
      							  return console.log(err);
    						}

    						console.log("The '" +nome+  "' file was saved! file: "+i+" de "+obj.length +'. ' );
						});
						fs.appendFile('tudo.csv', strig, function(err) {
    						if(err) {
      							  return console.log(err);
    						}

    						console.log("The file was saved!");
						}); 


  					});
  				});
  				
  			});

  		}
  });
  
  //console.log('body:',$('#ps').nextAll()); 
   
});