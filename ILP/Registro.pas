Program Estoque_Empresa;
Uses crt;

Type RProduto = Record
  Codigo: Integer;
  Nome_produto: String;
  Quant_estoq: Integer;
  Quant_min_estoq: Integer;
  Valor_produto: Real;
End;
Type RVenda = Record
  Cod_venda: String[30];
  Cod_prod_vendido: String[30];
  Quant_venda: Integer;
  Data_venda: String[10];
  Valor_venda: Real;
End;
Var
opcao: integer;
produto: array [1..2] of RProduto;
venda: array [1..2] of RVenda;
i: integer;
cont_venda: integer;

Procedure Menu;
Begin
  Clrscr;
  Writeln ('**********MENU**********');
  Writeln ('1 - Cadastrar Produto');
  Writeln ('2 - Cadastrar Venda');
  Writeln ('3 - Atualizar Estoque');
  Writeln ('4 - N£mero de vendas de um determinado dia');
  Writeln ('5 - O faturamento das vendas de um determinado dia');
  Writeln ('6 - Consultar todos os produtos que precisam atualizar o seu estoque');
  Writeln ('7 - Sair do Programa');
  Writeln;
  Writeln ('Selecione uma opá∆o:');
  Readln (opcao);
End;

Procedure CadastroP;
  Begin
For i:=1 to 2 do
  Begin
Write ('Digite o nome do produto a ser cadastrado:');
Readln (produto[i].nome_produto);
Write ('Digite a quantidade do produto em estoque:');
Readln (produto[i].quant_estoq);
Write ('Digite a quantidade m°nima de estoque:');
Readln (produto[i].quant_min_estoq);
Write ('Digite o valor do produto:');
Readln (produto[i].valor_produto);
  End;
  End;

Procedure CadastroV;
  Begin
For i:=1 to 2 do
  Begin
cont_venda := 0;
Write ('Digite o c¢digo da venda:');
Readln (venda[i].cod_venda);
Write ('Digite o c¢digo do produto vendido:');
Readln (venda[i].cod_prod_vendido);
Write ('Digite a quantidade vendida:');
Readln (venda[i].quant_venda);
Write ('Digite a data em que a venda foi efetuada (DD/MM/AAAA):');
Readln (venda[i].data_venda);
Write ('Digite o valor da venda efetuada:');
Readln (venda[i].valor_venda);
  End;
  End;

Procedure Atualizar_estoq;
Var estoq_atual: integer;
quant_venda: integer;
quant_estoq: integer;
  Begin
Write ('Digite a quantidade em estoque:');
Readln (quant_estoq);
Write ('Digite a quantidade que foi vendida:');
Readln (quant_venda);
estoq_atual := quant_estoq - quant_venda;
Writeln ('O seu estoque atual Ç: ', estoq_atual);
End;


Procedure LocalizarNumVendas;
Var  Dia: string[10];
  achou: boolean;
  Begin
Write ('Informe o dia em que a venda foi efetuada:');
Readln (Dia);
Achou := false;
For i:=1 to 2 do
Begin
  If dia = venda[i].data_venda then
  Write ('O n£mero de vendas foi:', venda[i].quant_venda);
  achou := true;
  Break;
End;
Begin
If not achou then
Writeln ('Data n∆o existe!');
End;
End;

Procedure Fatur_vendas;
Var  Dia: string[10];
  achou: boolean;
Begin
  Write ('Digite o dia em que vocà deseja procurar o faturamento:');
  Readln (Dia);
  Achou := false;
  For i:=1 to 2 do
  Begin
  If dia = venda[i].data_venda then
  Write ('O faturamento da venda foi: ', venda[i].valor_venda);
  Achou := true;
  Break;
  End;
If not achou then
Writeln ('Data n∆o existe!');
End;

Procedure Consult_Lista;
Var i: integer;
nome: string[30];
n: char;
resposta: integer;
  Begin
  Clrscr;
Write ('Tem algum produto a ser atualizado no estoque(s/n):');
Readln(n) ;
If n = 's' then
  Begin
Writeln ('Quantos produtos precisam ser atualizados:');
Readln (resposta);
For i:=1 to resposta do
Begin
  Writeln ('Digite o produto que precisa atualizar em seu estoque:');
  Readln (nome);
If nome = produto[i].nome_produto then
Writeln ('Produto: ',produto[i].nome_produto)
Else
Writeln ('Produto n„o encontrado!');
End;
End
Else
  Writeln ('N∆o existe produto que precisam ser atualizados em estoque!');
End;

 Begin
  Repeat
  Menu;
  Case opcao of
1: CadastroP;
2: CadastroV;
3: Atualizar_estoq;
4: LocalizarNumVendas;
5: Fatur_vendas;
6: Consult_lista;
7: Writeln ('Programa Finalizado!');
  Else
  Writeln ('Opá∆o Inv lida!');
  End;
  Until (opcao = 7);
 Readkey;
End.

