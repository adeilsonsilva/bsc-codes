program LOJA_BRINDES;
uses crt;
var opcao,Resp:char;


procedure Cad_Vendedores;
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

end;

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
 readln(opcao);
 ClrScr;
end;
begin
MENU;
while opcao <>'8' do
      if opcao='1' then
       begin
        writeln('Voce esta no menu de cadastramento de vendedores.');
       writeln('Deseja cadastrar um novo vendedor (s/n)?');
        readln(Resp);
         if Resp='s'
         then
           begin
            Clrscr;
            Cad_Vendedores;
           end
         else
           begin
            Clrscr;
            MENU;
           end;
       end;
readln;

end.
