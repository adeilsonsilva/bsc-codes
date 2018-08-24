Program SisCompras;
   Uses CRT;
   //Declaração da estrutura do registro de Produto.
   Type Produto = Record
          PROD_ID         : Integer;
          PROD_Nome       : String[30];
          PROD_Marca      : String[30];
          PROD_Sessao     : String[30];
          PROD_Preco      : Real;
          PROD_Qtd        : Integer;
          PROD_QtdVendido : Integer;
    End;

    //Declaração da estrutura do registro de Pedido.
    Type Pedido = Record
         PEDI_ID    : Integer;
         PROD_ID    : Integer;
         PEDI_Qtd   : Integer;
     End;

    //Definição do arquivo de registro apartir do registro "Produto".
    TArqProduto = file of Produto;
    //Definição do arquivo de registro apartir do registro "Pedido".
    TArqPedido  = file of Pedido;

    //Definição do diretório onde ficaram localizados os arquivos com os dados.
    Const _dirProd = 'C:\Users\Pedro\Desktop\Produtos.arq';
          _dirPedi = 'C:\Users\Pedro\Desktop\Pedidos.arq';

    //Declaração de variaveis de escorpo global que podem ser utilizadas por toda aplicação.
    var
        _arqProd         : TArqProduto;
        _arqPedi         : TArqPedido;
        _op              : Integer;
        _prod, _prodTemp : Produto;
        _pedi            : Pedido;
        _posicao         : Integer;

//Procedimento responsavel pelo a gravação dos dados no arquivo da aplicação.
Procedure prcGravaDados(pTipoGravacao : Integer);
Begin
     //[1] Grava Produtos [2]Grava Pedidos [3] Atualiza produto
     if (pTipoGravacao = 1) or (pTipoGravacao = 3)  then
        Begin
             Assign(_arqProd, _dirProd);
             Reset(_arqProd);
             if (pTipoGravacao = 1) then
                Seek(_arqProd,FileSize(_arqProd));

             if (pTipoGravacao = 3) then
                Seek(_arqProd,_posicao);

             Write(_arqProd, _Prod);
             Close(_arqProd);
        End
     else if pTipoGravacao = 2 then
          Begin
             Assign(_arqPedi, _dirPedi);
             Reset(_arqPedi);
             Seek(_arqPedi,FileSize(_arqPedi));
             Write(_arqPedi,_Pedi);
             Close(_arqPedi);
          End;

    if (pTipoGravacao = 1) or (pTipoGravacao = 2) then
       Begin
            Writeln('| Dados salvos com sucesso!');
            Readln();
       End;
End;

// Procedimento responsável pela a renderização de um produto na tela.
Procedure prcExibeProduto(p : Produto);
Begin
     Writeln('| Id............: ',p.Prod_id);
     Writeln('| Nome .........: ',p.Prod_Nome);
     Writeln('| Marca ........: ',p.Prod_Marca);
     Writeln('| Sessao .......: ',p.Prod_Sessao);
     Writeln('| Preco ........: ',p.Prod_Preco);
     Writeln('| Qtd Estoque ..: ',p.Prod_Qtd);
     writeln('| Qtd Vendido ..: ',p.Prod_QtdVendido);
     Writeln('');
End;

//Procedimento para a consulta de dados no arquivo da aplicação.
Procedure prcConsultadados(Var pFile : TArqProduto; pId : Integer; pNome : String; pSessao : String; pTipo : Integer);
     Var        p : Produto;
         _retorno : Boolean;
         _count   : Integer;
Begin
     _retorno := false;
     _count   := 0;
     _posicao := -1;
     //Inicia o processo de abertura do arquivo e a leitura do mesmo até chegar o seu final.
     Assign(_arqProd, _dirProd);
     Reset(pFile);

     While Not EOF(pFile) Do
           Begin
                Read(pFile,p);
                Case pTipo of    //[1]ID [2]Nome [3]Sessão. [4] ID para o pedido [0]Todos
                     1 : Begin
                              if p.PROD_ID = pId then
                                 _retorno := true;
                         End;
                     2 : Begin
                              if upCase(p.PROD_NOME) = upCase(pNome) then
                                 _retorno := true;
                         End;
                     3 : Begin
                              if upCase(p.PROD_Sessao) = upCase(pSessao) then
                                 _retorno := true;
                         End;
                     4 : Begin
                              if p.PROD_ID = pId then
                                 _retorno := true;
                         End;
                     0 : Begin
                              if p.PROD_Qtd > 0 then
                                 _retorno := true;
                         End;
                End;

                If _retorno = true then //Setar os valores encontrados na busca
                   Begin
                      _Prod.PROD_ID     := p.PROD_ID;
                      _Prod.PROD_Nome   := p.PROD_Nome;
                      _Prod.PROD_Marca  := p.PROD_Marca;
                      _Prod.PROD_Sessao := p.PROD_Sessao;
                      _Prod.PROD_Preco  := p.PROD_Preco;
                      _Prod.PROD_Qtd    := p.PROD_Qtd;
                      _Prod.PROD_QtdVendido := p.PROD_QtdVendido;

                      if  pTipo <> 4 then
                          prcExibeProduto(_Prod);

                      _retorno := false;
                      _count   := _count + 1;
                      _posicao := Filepos(pFile) -1 ;
                   End;
            End;
     if (_retorno = false)  and (_count = 0) then
        Writeln('| A busca não retornou dados.');

     Close(pFile);
End;

//Procedimento responsavel pela a gravação dos dados na variavel de produtos.
Procedure prcInsereProduto();
Begin
     Write('| Id............: ');
     Readln(_prodTemp.Prod_id);
     Write('| Nome .........: ');
     Readln(_prodTemp.Prod_Nome);
     Write('| Marca ........: ');
     Readln(_prodTemp.Prod_Marca);
     Write('| Sessao .......: ');
     Readln(_prodTemp.Prod_Sessao);
     Write('| Preco ........: ');
     Readln(_prodTemp.Prod_Preco);
     Write('| Qtd Estoque ..: ');
     Read(_prodTemp.Prod_Qtd); _prodTemp.Prod_QtdVendido := 0;
     Writeln('');

     prcConsultadados(_arqProd, _prodTemp.Prod_id, '', '',4);
End;

//Procedure responsável pelo cadastramento dos produtos pelo o usuário.
Procedure prcCadastrarProduto;
Begin
     Clrscr;
     Writeln('+--------------------------------------------------------+');
     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('|ªªªªªªªªªªªªªªª Cadastro de Produtos ªªªªªªªªªªªªªªªªªªª|');
     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('+--------------------------------------------------------+');
     Writeln('');
     prcInsereProduto;

     _Prod.PROD_ID     := _ProdTemp.PROD_ID;
     _Prod.PROD_Nome   := _ProdTemp.PROD_Nome;
     _Prod.PROD_Marca  := _ProdTemp.PROD_Marca;
     _Prod.PROD_Sessao := _ProdTemp.PROD_Sessao;
     _Prod.PROD_Preco  := _ProdTemp.PROD_Preco;
     _Prod.PROD_Qtd    := _ProdTemp.PROD_Qtd;
     _Prod.PROD_QtdVendido := _ProdTemp.PROD_QtdVendido;

     if _posicao = -1 then
        Begin
            prcGravaDados(1);
        End
     Else
        Begin
            Write('| Produto ja cadastrado. Deseja atualza-lo? Sim [1] Nao [2] ');
            Readln(_op);
            if _op = 1 then
               Begin
                    prcGravaDados(3);
                    Writeln('');
                    Writeln('| Dados salvos com sucesso!')
               End;
     End;
     Readln();
End;

//Procedure para consultar produtos cadastrados.
Procedure prcConsultaProduto;
      var _TipoBusca, _Id : Integer;
          _Nome           : String;
Begin
     _Nome := '';
     _Id   := 0;

     Clrscr;
     Writeln('+--------------------------------------------------------+');
     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('|ªªªªªªªªªªªªªªªªªª Busca de Produtos ªªªªªªªªªªªªªªªªªªª|');
     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('+--------------------------------------------------------+');
     Writeln('| [1] Por ID [2] Por Nome                                |');
     Writeln('+--------------------------------------------------------+');
     Write('|Op: ');
     Readln(_TipoBusca);
     Writeln('');

     If _TipoBusca = 1 then
        Begin
             Write('| Informe o Id do produto: ');
             Readln(_Id);
        End
     Else if _TipoBusca = 2 then
        Begin
           Write('| Informe o Nome do produto: ');
           Readln(_Nome);
        End;
     Writeln('');

     if (_TipoBusca = 1) or (_TipoBusca = 2) then
        prcConsultadados(_arqProd, _Id, _Nome, '', _TipoBusca);

     Readln();
End;

//Procedimento responsável pela a exibição dos produtos de uma sessão.
Procedure prcExibeProdutoSessao();
      var _Sessao : String;
Begin
     Clrscr;
     Writeln('+--------------------------------------------------------+');
     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('|ªªªªªªªªªªªªªªªListar Pordutos Sessaoªªªªªªªªªªªªªªªªªªª|');
     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('+--------------------------------------------------------+');
     Writeln('');
     Write('Informe a sessao:');
     Readln(_sessao);
     prcConsultadados(_arqProd, 0, '', _Sessao, 3);
     readln();
End;

//Procedimento responsavel pela a geração do pedido em um arquivo separado do cadastro
// dos produtos dando baixa no estoque dos produtos.
Procedure prcPedido();
      Var _Opc, _count : Integer;
          _total       : Real;
Begin
     Clrscr;
     Writeln('+--------------------------------------------------------+');
     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('|ªªªªªªªªªªªªªªªªªª Pedido de Produtos ªªªªªªªªªªªªªªªªªª|');
     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('+--------------------------------------------------------+');
     Writeln('| [1] Listar Produtos [2] Incluir [3] Finalizar Pedido   |');
     Writeln('');
     Write('| Op: ');
     Readln(_opc);

     if _opc = 1 then
        prcConsultadados(_arqProd, 0, '', '', 0);

     Writeln('');
     Write('| Informe o ID do Pedido: ');
     Readln(_pedi.PEDI_ID);
     Writeln('');

     _opc   := 2;
     _count := 0;
     _posicao := -1;
     _total := 0;

     While _opc = 2 Do
         Begin
              Write('| ID do produto .: ');
              Readln(_pedi.PROD_ID);
              Write('| Qtd ...........: ');
              Readln(_pedi.PEDI_Qtd);
              prcConsultadados(_arqProd, _pedi.PROD_ID, '', '', 4);

              if (_prod.prod_qtd - _pedi.PEDI_Qtd) < 0 then
                 Begin
                      Writeln('');
                      Writeln('| Qtd do produto indisponivel em estoque.');
                 End
              else
                 Begin
                      _total := _total + _prod.prod_preco;
                      _count := _count + 1;

                      _prod.prod_qtd        := _prod.prod_qtd - _pedi.PEDI_Qtd;
                      _prod.Prod_QtdVendido := _prod.Prod_QtdVendido + _pedi.PEDI_Qtd;
                      prcGravaDados(3);
                      prcGravaDados(2);
                 End;
              Writeln('');
              Write('| Op: ');
              Readln(_opc);
         End;
     Writeln('');
     Writeln('| Total pedido ....: ', _Total);
     Writeln('| Total de itens ..:', _count);
     Readln();
End;

//Procedure para eleger os produtos mais vendidos.
Procedure prcMaisPedidos;
      Var _Id1, _Id2, _Id3    : Integer;
          _Qtd1, _Qtd2, _Qtd3 : Integer;
          _p                  : Produto;
Begin
     _Qtd1 := 0; _Qtd2 := 0; _Qtd3 := 0;

     Assign(_arqProd, _dirProd);

     //Busca o produto mais vendido.
     Reset(_arqProd);
     While Not EOF(_arqProd) Do
           Begin
                Read(_arqProd, _p);
                if _Qtd1 < _p.Prod_QtdVendido then
                   Begin
                        _qtd1 := _p.Prod_QtdVendido;
                        _Id1  := _p.Prod_ID;
                   End;
           End;
     Close(_arqProd);

     //Busca o segundo produto mais vendido.
     Reset(_arqProd);
     While Not EOF(_arqProd) Do
           Begin
                Read(_arqProd, _p);
                if (_Qtd2 < _p.Prod_QtdVendido) and (_p.Prod_QtdVendido < _Qtd1) then
                   Begin
                        _Id2  := _p.PROD_ID;
                        _qtd2 := _p.Prod_QtdVendido;
                   End;
           End;
     Close(_arqProd);

     //Busca o terceiro produto mais vendido.
     Reset(_arqProd);
     While Not EOF(_arqProd) Do
           Begin
                Read(_arqProd, _p);
                if (_Qtd3 < _p.Prod_QtdVendido) and (_p.Prod_QtdVendido < _Qtd2) and (_p.Prod_QtdVendido < _Qtd1) then
                   Begin
                        _Id3  := _p.PROD_ID;
                        _qtd3 := _p.Prod_QtdVendido;
                   End;
           End;
     Close(_arqProd);

     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('|ªªªªªªªªªªªªªªªªªªª Produto 1 ªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('');
     prcConsultadados(_arqProd, _Id1, '', '', 1);

     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('|ªªªªªªªªªªªªªªªªªªª Produto 2 ªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('');
     prcConsultadados(_arqProd, _Id2, '', '', 1);

     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('|ªªªªªªªªªªªªªªªªªªª Produto 3 ªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('');
     prcConsultadados(_arqProd, _Id3, '', '', 1);
     Readln();
     _Qtd1 := 0; _Qtd2 := 0; _Qtd3 := 0;
End;

//Procedure para zerar os arquivos de pedidos e produtos
Procedure prcZeraArquivos;
Begin
   Assign(_arqProd, _dirProd);
   ReWrite(_arqProd);
   Assign(_arqPedi, _dirPedi);
   ReWrite(_arqPedi);
   Close(_arqPedi);
   Close(_arqProd);
   Writeln('');
   Writeln('| Arquivos limpos com sucesso!');
   Readln();
End;

//Procedure responsavel pela a renderização do menu principal na tela da aplicação.
Procedure prcMenu;
Begin
     Clrscr;
     Writeln('+--------------------------------------------------------+');
     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªSisProdªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('|ªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªªª|');
     Writeln('+--------------------------------------------------------+');
     Writeln('| [1] Cadastrar Produto     [2] Buscar Produto           |');
     Writeln('| [3] Produtos por sessao   [4] Efetuar Pedido           |');
     Writeln('| [5] Produtos mais pedidos [6] Criar/Recriar Arquivos   |');
     Writeln('|                           [7] Sair                     |');
     Writeln('+--------------------------------------------------------+');
     Write('|Op|: ');
     Readln(_op);
End;

//Programa onde é realizada a chamada das rotinas da aplicação
Begin
    While _op <> 7 Do
          Begin
               Case _op of
                    0 : prcMenu;
                    1 : prcCadastrarProduto;
                    2 : prcConsultaProduto;
                    3 : prcExibeProdutoSessao;
                    4 : prcPedido;
                    5 : prcMaisPedidos;
                    6 : prcZeraArquivos;
               Else
                   Writeln('Opção digitada nao disponivel na aplicacao!');
                   _op := 0;
               End;
               prcMenu;
          End;
End.

