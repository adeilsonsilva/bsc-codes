Program Teste_Registro ;
type Cad=Record
     Codigo: String[10];
     Nome:String[30];
     Endereco:String[80];
     Telefone:String[8];
     Admissao:String[10];
    end; 
var vendedor:cad;
Begin  
   writeln('Digite o codigo do vendedor:');
   readln(vendedor.Codigo);
  writeln('Digite o nome do vendedor:');
   readln(vendedor.Nome);
  writeln('Digite o endereco do vendedor:');
   readln(vendedor.Endereco);
  writeln('Digite o telefone do vendedor:');
   readln(vendedor.Telefone);
  writeln('Digite a data de admissao do vendedor:');
   readln(vendedor.Admissao);
  writeln;
  writeln;
  writeln;
  writeln('O codigo do vendedor e:',vendedor.Codigo);
  writeln('O Nome do vendedor e:',vendedor.Nome);
  writeln('O Endereco do vendedor e:',vendedor.Endereco);
  writeln('O Telefone do vendedor e:',vendedor.Telefone);
  writeln('A data de admissao do vendedor e:',vendedor.Admissao);
  readln;
  
End.
