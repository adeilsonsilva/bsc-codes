program LOJA_BRINDES;
uses crt;
type Cad=Record
     Codigo: array[1..20] of String[10];
     Nome: array[1..20] of String[30];
     Endereco: array[1..20] of String[80];
     Telefone: array[1..20] of String[8];
     Admissao: array[1..20] of String[10];
    end; 
var i: integer;
    opcao,Resp:char;
    vendedor:Cad;
    arqvendedor: file of Cad;

    //PRODCEDIMENTO PRA GERAR OS ARQUIVOS

procedure Gera_Arquivos;
 begin
   writeln('Gerando arquivos do sistema...');
   readln();
   Assign(arqvendedor,'C:\vendedores.arq');
   rewrite(arqvendedor);
   writeln('Arquivos gerados com sucesso!');
   readln();
  end;

  //PROCEDIMENTO PARA MOSTRAR OS VENDEDORES

procedure Mostra_Vend;
begin
Assign(arqvendedor,'C:\vendedores.arq');
reset(arqvendedor);
read(arqvendedor,vendedor);
writeln('CODIGO:',vendedor.Codigo[i]);
writeln('NOME:',vendedor.Nome[i]);
writeln('ENDERECO:',vendedor.Endereco[i]);
writeln('TELEFONE',vendedor.Telefone[i]);
writeln('ADMISSAO:',vendedor.Admissao[i]);
end;

   //PROCEDIMENTO DE CADASTRO DOS VENDEDORES

procedure Cad_Vendedores;
Begin
   for i:=1 to 20 do
    begin
     writeln;
     writeln('Digite o codigo do vendedor:');
     readln(vendedor.Codigo[i]);
     writeln;
     writeln('Digite o nome do vendedor:');
     readln(vendedor.Nome[i]);
     writeln;
     writeln('Digite o endereco do vendedor:');
     readln(vendedor.Endereco[i]);
     writeln;
     writeln('Digite o telefone do vendedor:');
     readln(vendedor.Telefone[i]);
     writeln;
     writeln('Digite a data de admissao do vendedor:');
     readln(vendedor.Admissao[i]);
     writeln;
   end;
Assign(arqvendedor,'C:\vendedores.arq');
Reset(arqvendedor);
Write(arqvendedor,vendedor);
Writeln('Dados gravados com sucesso!');
readln();
end;
   //MENU
procedure MENU;
begin
 writeln('BEM VINDO AO SISTEMA DA LOJA DE BRINDES ARVD');
 writeln('Escolha uma opcao no menu abaixo:');
 writeln('1- Cadastrar vendedores');
 writeln('2- Cadastrar pedidos');
 writeln('3- Estoque de brindes');
 writeln('4- Informar precos dos brindes');
 writeln('5- Consultar situação do pedido do cliente');
 writeln('6- Alterar situacao do pedido');
 writeln('7- Gerar arquivo de movimento por periodo');
 writeln('8- Sair');
 writeln;
 write('Digite sua opcao:');
 read(opcao);
 ClrScr;
end;

      //INÍCIO DO PROGRAMA PRINCIPAL

BEGIN
Gera_Arquivos;
Clrscr;
MENU;
case opcao of
    '1': begin
         Clrscr;
         writeln('Voce esta no menu de Cadastro de Vendedores.');
         writeln;
         Cad_Vendedores;
         readln;
         writeln('Deseja ver vendedores cadastrados(s/n)?');
         readln(Resp);
          if Resp='s' then
           for i:=1 to 20 do
            begin
            Mostra_Vend;
           end;
          end;

         end;

END.
