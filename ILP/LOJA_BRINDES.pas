
program LOJA_BRINDES;
uses crt;
type Cad=Record
     Codigo: String[10];
     Nome:String[30];
     Endereco:String[80];
     Telefone:String[10];
     Admissao:String[10];
    end; 

type Ped=Record
     Numpedido: Integer;
     Datapedido: String[10];
     NomeCliente: String[30];
     NomeVendedor: String[30];
     Qcaneca:integer;
     Qbone:integer;
     Qchaveiro:integer;
     Qcaneta:integer;
     Qportalapis:integer;
     Qagenda:integer;
     Qportaretrato:integer;
    end;

type Quant=Record
     Caneca:integer;
     Bone:integer;
     Chaveiro:integer;
     Caneta:integer;
     Portalapis:integer;
     Agenda:integer;
     PortaRetrato:integer;
     end;

type Pre=Record
     Caneca: real;
     Bone:real;
     Chaveiro:real;
     Caneta:real;
     Portalapis:real;
     Agenda:real;
     PortaRetrato:real;
    end;

var opcao,Resp,Resp2,Resp3,Resp4,Resp5:char;
    AUX1,AUX2,VALOR,VALOR2:Integer;
    Quantidade:Quant;
    Preco:Pre;
    Pedido:Ped;
    vendedor:Cad;
    arqpedido: file of Ped;
    arqquantidade: file of Quant;
    arqpreco: file of Pre;
    arqvendedor: file of Cad;


      //PROCEDIMENTO DE CALCULO DOS PEDIDOS

procedure Calc_Pedidos;
var ValorCa,ValorB,ValorCha,ValorCan,ValorPL,ValorA,ValorPR,ValorTOTAL: real;
Begin
 Assign(arqpreco,'C:\preços.arq');
 reset(arqpreco);
  Assign(arqpedido,'C:\pedidos.arq');
 reset(arqpedido);
while not Eof(arqpreco) and Eof(arqpedido)do
  begin
   read(arqpreco, preco);
   ValorCa:= preco.Caneca*pedido.Qcaneca;
   ValorB:= preco.bone*pedido.Qbone;
   ValorCha:=preco.chaveiro*pedido.Qchaveiro;
   ValorCan:=preco.caneta*pedido.Qcaneta;
   ValorPL:=preco.portalapis*pedido.Qportalapis;
   ValorA:=preco.agenda*pedido.Qagenda;
   ValorPR:=preco.portaretrato*pedido.Qportaretrato;
   ValorTOTAL:=ValorCA+ValorB+ValorCha+ValorCan+ValorPL+ValorA+ValorPR;
  end;
  writeln('Valor total do pedido: ',ValorTOTAL);
  readln;
  Close(arqpreco);
end;

      //PROCEDIMENTO DE CADASTRO DE PEDIDOS

procedure Cad_Pedidos;
Begin
     Assign(arqpedido,'C:\pedidos.arq');
     {$I-}
    Reset(arqpedido);
     {$I+}
    if IORESULT()<>0 then
     begin
     ReWrite(arqpedido);
     Reset(arqpedido);
     end
     else
     begin
     Seek (arqpedido, FileSize(arqpedido));
     end;
     writeln;
     writeln('Digite o Numero do pedido:');
     readln(Pedido.Numpedido);
     writeln;
     writeln('Digite a data do pedido:');
     readln(Pedido.Datapedido);
     writeln;
     writeln('Digite o nome do Cliente:');
     readln(Pedido.NomeCliente);
     writeln;
     writeln('Digite o nome do vendedor:');
     readln(Pedido.NomeVendedor);
     writeln;
     writeln('Digite a quantidade de canecas desejadas:');
     readln(Pedido.Qcaneca);
     writeln;
     writeln('Digite a quantidade de bones desejados:');
     readln(Pedido.Qbone);
     writeln;
    writeln('Digite a quantidade de chaveiros desejados:');
     readln(Pedido.Qchaveiro);
     writeln;
     writeln('Digite a quantidade de canetas desejadas:');
     readln(Pedido.Qcaneta);
     writeln;
     writeln('Digite a quantidade de Porta-Lapis desejados:');
     readln(Pedido.Qportalapis);
     writeln;
     writeln('Digite a quantidade de agendas desejadas:');
     readln(Pedido.Qagenda);
     writeln;
     writeln('Digite a quantidade de Porta-Retratos desejados:');
     readln(Pedido.Qportaretrato);
     writeln;
Write(arqpedido, pedido);
Writeln('Dados gravados com sucesso!');
readln;
Close(arqpedido);
readln;
 end;

                 //FUNÇÃO DE CONSULTA NO ARQUIVO DOS PEDIDOS

function Consulta_Ped(var arqpedido : File of Ped; NumP: integer; var Pedido:Ped):integer;
begin
Clrscr;
Assign(arqpedido,'C:\pedidos.arq');
     {$I-}
    Reset(arqpedido);
     {$I+}
    if IORESULT()<>0 then
     begin
     ReWrite(arqpedido);
     Reset(arqpedido);
     end;
writeln;
writeln('Digite o numero do pedido:');
readln(NumP);
writeln;
while not Eof(arqpedido) and(Pedido.NumPedido<>NumP) do
read(arqpedido, Pedido);
if Pedido.NumPedido = NumP
then
begin
AUX2:=1;
writeln('NUMERO DO PEDIDO: ', pedido.Numpedido);
writeln;
writeln('PEDIDO EXPEDIDO EM: ', pedido.Datapedido);
writeln;
writeln('NOME DO CLIENTE: ', pedido.NomeCliente);
writeln;
writeln('NOME DO VENDEDOR: ', pedido.NomeVendedor);
writeln;
writeln('QUANTIDADE DE CANECAS PEDIDAS: ', pedido.Qcaneca);
writeln;
writeln('QUANTIDADE DE BONES PEDIDOS: ', pedido.Qbone);
writeln;
writeln('QUANTIDADE DE CHAVEIROS PEDIDOS: ', pedido.Qchaveiro);
writeln;
writeln('QUANTIDADE DE CANETAS PEDIDAS: ', pedido.Qcaneta);
writeln;
writeln('QUANTIDADE DE PORTA-LAPIS PEDIDOS: ', pedido.Qportalapis);
writeln;
writeln('QUANTIDADE DE AGENDAS PEDIDAS: ', pedido.Qagenda);
writeln;
writeln('QUANTIDADE DE PORTA-RETRATOS PEDIDOS: ', pedido.Qportaretrato);
Consulta_Ped:=FilePos(arqpedido);
readln;
end
else
begin
AUX2:=2;
writeln('Numero de Pedido nao existente!');
readln;
Consulta_Ped:= -1;
end;
readln;
end;


      //PROCEDIMENTO DE CADASTRO DA QUANTIDADE DE BRINDES

procedure Cad_Quantidade;
Begin
     Assign(arqquantidade,'C:\quantidade.arq');
     {$I-}
    Reset(arqquantidade);
     {$I+}
    if IORESULT()<>0 then
     begin
     ReWrite(arqquantidade);
     Reset(arqquantidade);
     end
     else
     begin
     Seek (arqquantidade, FilePos(arqquantidade));
     end;
     writeln;
     writeln('Digite a quantidade de canecas em estoque:');
     readln(Quantidade.Caneca);
     writeln;
     writeln('Digite a quantidade de bones em estoque:');
     readln(Quantidade.Bone);
     writeln;
     writeln('Digite a quantidade de chaveiros em estoque:');
     readln(Quantidade.chaveiro);
     writeln;
     writeln('Digite a quantidade de canetas em estoque:');
     readln(Quantidade.caneta);
     writeln;
     writeln('Digite a quantidade de porta-lapis em estoque:');
     readln(Quantidade.portalapis);
     writeln;
     writeln('Digite a quantidade de agendas em estoque:');
     readln(Quantidade.agenda);
     writeln;
     writeln('Digite a quantidade de porta-retratos em estoque:');
     readln(Quantidade.portaretrato);
     writeln;
Write(arqquantidade, quantidade);
Writeln('Dados gravados com sucesso!');
readln;
Close(arqquantidade);
readln;
 end;

     //PROCEDIMENTO DE CADASTRO DOS PREÇOS

procedure Cad_Precos;
Begin
     Assign(arqpreco,'C:\preços.arq');
     {$I-}
    Reset(arqpreco);
     {$I+}
    if IORESULT()<>0 then
     begin
     ReWrite(arqpreco);
     Reset(arqpreco);
     end
     else
     begin
     Seek (arqpreco, FilePos(arqpreco));
     end;
     writeln;
     writeln('Digite o preco da caneca:');
     readln(Preco.Caneca);
     writeln;
     writeln('Digite o preco do bone:');
     readln(Preco.Bone);
     writeln;
     writeln('Digite o preco do chaveiro:');
     readln(preco.chaveiro);
     writeln;
     writeln('Digite o preco da caneta:');
     readln(preco.caneta);
     writeln;
     writeln('Digite o preco do porta-lapis:');
     readln(preco.portalapis);
     writeln;
     writeln('Digite o preco da agenda:');
     readln(preco.agenda);
     writeln;
     writeln('Digite o preco do porta-retrato:');
     readln(preco.portaretrato);
     writeln;
Write(arqpreco, preco);
Writeln('Dados gravados com sucesso!');
readln;
Close(arqpreco);
readln;
 end;

             //PROCEDIMENTO PARA MOSTRAR OS PREÇOS

procedure Mostra_Preco;
begin
Clrscr;
Assign(arqpreco,'C:\preços.arq');
reset(arqpreco);
while not Eof(arqpreco) do
begin
read(arqpreco, Preco);
writeln('PRECO DA CANECA: ',Preco.Caneca:6:2);
writeln('PRECO DO BONE: ',Preco.Bone:6:2);
writeln('PRECO DO CHAVEIRO: ',Preco.Chaveiro:6:2);
writeln('PRECO DA CANETA: ',Preco.Caneta:6:2);
writeln('PRECO DO PORTA-LAPIS: ',Preco.portalapis:6:2);
writeln('PRECO DA AGENDA: ',Preco.agenda:6:2);
writeln('PRECO DO PORTA RETRATO: ',Preco.portaretrato:6:2);
writeln;
writeln;
end;
close(arqpreco);
readln;
end;

           //FUNÇÃO DE CONSULTA NO ARQUIVO DE VENDEDORES

function Consulta_Vend(var arqvendedor : File of Cad; CodigoT : string[10]; var vendedor : Cad):integer;
begin
Clrscr;
Assign(arqvendedor,'C:\vendedores.arq');
     {$I-}
    Reset(arqvendedor);
     {$I+}
    if IORESULT()<>0 then
     begin
     ReWrite(arqvendedor);
     Reset(arqvendedor);
     end;
writeln;
writeln('Digite o codigo do vendedor:');
readln(CodigoT);
writeln;
while not Eof(arqvendedor) and(vendedor.codigo<>CodigoT) do
read(arqvendedor, vendedor);
if CodigoT=vendedor.codigo
then
begin
Consulta_Vend:=FilePos(arqvendedor);
AUX1:=1;
writeln('Este Codigo de vendedor ja consta no Sistema de Cadastro!');
writeln;
writeln;
writeln('CODIGO: ',vendedor.Codigo);
writeln;
writeln('NOME: ',vendedor.Nome);
writeln;
readln;
end
else
begin
AUX1:=2;
writeln('Codigo nao cadastrado!');
readln;
Consulta_Vend:= -1;
end;
Close(arqvendedor);
end;

            // PROCEDIMENTO DE ALTERAÇÃO DE PEDIDO

procedure Altera_Pedido(var arqpedido:file of Ped;var Pedido:Ped);
var m: integer;
RespCa,RespB,RespCh,RespCan,RespPL,RespA,RespPR:char;
begin
Clrscr;
Assign(arqpedido,'C:\pedidos.arq');
Reset(arqpedido);
m:= VALOR2;
if m <> -1 then
begin
writeln('ALTERANDO CADASTROS JÁ REALIZADOS');
writeln;
writeln;
writeln('Deseja alterar a quantidade de canecas? (s/n)');
readln(RespCa);
writeln;
if RespCa='s'then
begin
writeln('Digite a nova quantidade.');
readln(pedido.Qcaneca);
Seek(arqvendedor, m);
write(arqpedido, pedido);
writeln;
end;
writeln('Deseja alterar a quantidade de bones? (s/n)');
readln(RespB);
writeln;
if RespB='s'then
begin
writeln('Digite a nova quantidade.');
readln(pedido.Qbone);
Seek(arqvendedor, m);
write(arqpedido, pedido);
writeln;
end;
writeln('Deseja alterar a quantidade de chaveiros? (s/n)');
readln(RespCh);
writeln;
if RespCh='s'then
begin
writeln('Digite a nova quantidade.');
readln(pedido.Qchaveiro);
Seek(arqvendedor, m);
write(arqpedido, pedido);
writeln;
end;
writeln('Deseja alterar a quantidade de canetas? (s/n)');
readln(RespCan);
writeln;
if RespCan='s'then
begin
writeln('Digite a nova quantidade.');
readln(pedido.Qcaneta);
Seek(arqvendedor, m);
write(arqpedido, pedido);
writeln;
end;
writeln('Deseja alterar a quantidade de porta-lapis? (s/n)');
readln(RespPL);
writeln;
if RespPL='s'then
begin
writeln('Digite a nova quantidade.');
readln(pedido.Qportalapis);
Seek(arqvendedor, m);
write(arqpedido, pedido);
writeln;
end;
writeln('Deseja alterar a quantidade de agendas? (s/n)');
readln(RespA);
writeln;
if RespA='s'then
begin
writeln('Digite a nova quantidade.');
readln(pedido.Qportalapis);
Seek(arqvendedor, m);
write(arqpedido, pedido);
writeln;
end;
writeln('Deseja alterar a quantidade de Porta-Retratos? (s/n)');
readln(RespPR);
writeln;
if RespPR='s'then
begin
writeln('Digite a nova quantidade.');
readln(pedido.Qportaretrato);
Seek(arqvendedor, m);
write(arqpedido, pedido);
writeln;
end;
readln;
end;
writeln('Dados sobrescritos com sucesso!');
Close(arqpedido);
readln;
end;

        // PROCEDIMENTO DE ALTERAÇÃO DE REGISTRO

procedure Altera_Registro(var arqvendedor:file of Cad;var vendedor:Cad);
var n: integer;
RespN,RespC,RespE,RespT,RespA:char;
begin
Clrscr;
Assign(arqvendedor,'C:\vendedores.arq');
Reset(arqvendedor);
n:= VALOR;
if n <> -1 then
begin
writeln('ALTERANDO CADASTROS JÁ REALIZADOS');
writeln;
writeln;
writeln('Deseja alterar o Codigo? (s/n)');
readln(RespC);
writeln;
if RespC='s'then
begin
Seek(arqvendedor, n);
writeln('Digite o novo Codigo.');
readln(vendedor.Codigo);
write(arqvendedor, vendedor);
writeln;
end;
writeln('Deseja alterar o Nome? (s/n)');
readln(RespN);
writeln;
if RespN='s' then
begin
Seek(arqvendedor, n);
writeln('Digite o novo Nome.');
readln(vendedor.Nome);
write(arqvendedor, vendedor);
writeln;
end;
writeln('Deseja alterar o Endereco? (s/n)');
Readln(RespE);
writeln;
if RespE='s' then
begin
Seek(arqvendedor, n);
writeln('Digite o novo Endereco.');
readln(vendedor.Endereco);
write(arqvendedor, vendedor);
writeln;
end;
writeln('Deseja alterar o Telefone? (s/n)');
readln(RespT);
writeln;
if RespT='s' then
begin
Seek(arqvendedor, n);
writeln('Digite o novo Telefone.');
readln(vendedor.Telefone);
write(arqvendedor, vendedor);
writeln;
end;
writeln('Deseja alterar a data de Admissao? (s/n)');
readln(RespA);
writeln;
if RespA='s' then
begin
Seek(arqvendedor, n);
writeln('Digite a nova Data.');
readln(vendedor.Admissao);
write(arqvendedor, vendedor);
writeln;
end;
readln;
end;
writeln('Dados sobrescritos com sucesso!');
Close(arqvendedor);
readln;
end;




    //PROCEDIMENTO DE CADASTRO DOS VENDEDORES

procedure Cad_Vendedores;
Begin
     Assign(arqvendedor,'C:\vendedores.arq');
     Reset(arqvendedor);
     Seek (arqvendedor, FileSize(arqvendedor));
     writeln;
     writeln('Digite o codigo do vendedor:');
     readln(vendedor.Codigo);
     writeln;
     writeln('Digite o nome do vendedor:');
     readln(vendedor.Nome);
     writeln;
     writeln('Digite o endereco do vendedor:');
     readln(vendedor.Endereco);
     writeln;
     writeln('Digite o telefone do vendedor:');
     readln(vendedor.Telefone);
     writeln;
     writeln('Digite a data de admissao do vendedor:');
     readln(vendedor.Admissao);
     writeln;
Write(arqvendedor,vendedor);
Writeln('Dados gravados com sucesso!');
readln;
Close(arqvendedor);
readln;
 end;



  //PROCEDIMENTO PARA MOSTRAR OS VENDEDORES

procedure Mostra_Vend;
begin
Clrscr;
Assign(arqvendedor,'C:\vendedores.arq');
reset(arqvendedor);
while not Eof(arqvendedor) do
begin
read(arqvendedor,vendedor);
writeln('CODIGO: ',vendedor.Codigo);
writeln('NOME: ',vendedor.Nome);
writeln('ENDERECO: ',vendedor.Endereco);
writeln('TELEFONE: ',vendedor.Telefone);
writeln('ADMISSAO: ',vendedor.Admissao);
writeln;
writeln;
end;
close(arqvendedor);
readln;
end;

      //INÍCIO DO PROGRAMA PRINCIPAL

BEGIN
repeat
begin
Clrscr;
writeln('BEM VINDO AO SISTEMA DA LOJA DE BRINDES ARVD');
 writeln('Escolha uma opcao no menu abaixo:');
 writeln('[1] - Cadastrar vendedores.');
 writeln('[2] - Cadastrar pedidos.');
 writeln('[3] - Estoque de brindes.');
 writeln('[4] - Informar precos dos brindes.');
 writeln('[5] - Consultar situacao do pedido do cliente.');
 writeln('[6] - Alterar situacao do pedido.');
 writeln('[7] - Gerar arquivo de movimento por periodo.');
 writeln('[8] - Sair.');
 writeln;
 write('Escolha sua opcao:');
 readln(opcao);
     if opcao='1' then
       begin
       Clrscr;
       writeln('Voce esta no MENU de Cadastro dos Vendedores.');
       writeln;
       writeln('Deseja realizar um novo cadastro (s/n)?');
       readln(Resp);
          if Resp='s' then
            begin
              Consulta_Vend(arqvendedor, vendedor.codigo, vendedor);
              if AUX1=1 then
               begin
              VALOR:=Consulta_Vend(arqvendedor, vendedor.codigo, vendedor);
              Altera_Registro(arqvendedor,vendedor);
               end
              else if AUX1=2then
               begin
                Clrscr;
                writeln('REALIZANDO NOVO CADASTRO...');
                writeln;
               Cad_Vendedores;
               end;
            end
          else if Resp='n' then
            begin
            writeln('Deseja visualizar os cadastros ja realizados(s/n)?');
            readln(Resp2);
              if Resp2='s' then
              begin
               MOSTRA_VEND;
              end;
           end;
        end
   else if opcao='2' then
      begin
      Clrscr;
      writeln('Voce esta no MENU de Cadastro de Pedidos.');
      writeln;
       writeln('Deseja realizar novo pedido? (s/n)?');
       readln(Resp5);
        if Resp5='s' then
         begin
          Clrscr;
          Cad_Pedidos;
         end;
      end
   else if opcao='3' then
      begin
       Clrscr;
       Cad_Quantidade;
      end
   else if opcao='4' then
     begin
       Clrscr;
       writeln('Voce esta no MENU de Cadastro dos Precos.');
       writeln;
      writeln('Deseja cadastrar novos precos ? (s/n)');
      readln(Resp3);
       if Resp3='s' then
       begin
        Clrscr;
        Cad_Precos;
       end
       else if Resp3='n' then
       begin
        writeln('Deseja visualizar precos ja registrados ? (s/n)');
        readln(Resp4);
         if Resp4='s' then
         begin
          Mostra_Preco;
         end;
       end;
     end
   else if opcao='5' then
     begin
      Clrscr;
      Consulta_Ped(arqpedido, pedido.NumPedido, pedido);
       if AUX2=1 then
       begin
      VALOR2:=Consulta_Ped(arqpedido, pedido.NumPedido, pedido);
      Close(arqvendedor);
       end;
       end
   else if opcao='6' then
     begin
      Clrscr;
      Consulta_Ped(arqpedido, pedido.NumPedido, pedido);
      Clrscr;
      Altera_Pedido(arqpedido, pedido);
      end
   else if opcao='7' then
     begin
      Clrscr;
      writeln('ERROR406');
     end;
   end;
  until opcao='8';
 writeln;
 writeln;
 writeln('SISTEMA FINALIZADO..');
 writeln;
 writeln;
 writeln('Volte sempre !');
 readln;

END.
