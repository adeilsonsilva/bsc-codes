package common.classesPessoas;

import inOut.Keyboard;
import common.classesAbstratas.Usuario;
import common.classesProdutos.*;
import java.util.ArrayList;

public class Funcionario extends Usuario {

    private double salario;
    private String escolaridade;
    private String CPF;
    private String dataAdmissao;
    private boolean logado;

    public Funcionario(String nome, String codigo, double salario, String escolaridade, String data, String endereco, String CPF, long telefone) {
        super(nome, codigo, endereco, telefone);
        this.dataAdmissao = data;
        this.salario = salario;
        this.escolaridade = escolaridade;
        this.CPF = CPF;
        this.logado = false;
    }

    public double getSalario() {
        return this.salario;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }

    public String getEscolaridade() {
        return this.escolaridade;
    }

    public void setEscolaridade(String escolaridade) {
        this.escolaridade = escolaridade;
    }

    public String getCPF() {
        return this.CPF;
    }

    public void setCPF(String cPF) {
        this.CPF = cPF;
    }

    public String getDataAdmissao() {
        return this.dataAdmissao;
    }

    public void setDataAdmissao(String dataAdmissao) {
        this.dataAdmissao = dataAdmissao;
    }

    public void abrirCaixa() {
        Caixa.valorAtual = 0;
    }

    public void valorCaixa() {
        System.out.println("O valor atual do caixa e: " + Caixa.valorAtual);
    }

    public boolean Login(String cpf) throws FuncLoginException {
        if (cpf.isEmpty()) {
            throw new FuncLoginException("Este CPF nao esta cadastrado.");
        }
        return this.CPF.equals(cpf);
    }

    public void logado() {
        ArrayList<Prateleira> prateleiras = new ArrayList<>();
        char resp;
        int quantidade;
        String nomePesquisa;
        String codigoPesquisa;
        Farmaco farmaco;

        this.logado();
        for (int i = 1; i <= Prateleira.qtdMaxPrateleiras; i++) {
            prateleiras.add(i, new Prateleira());
        }
        System.out.println("Bem vindo " + this.getNome() + "!!");
        do {
            System.out.println("Escolha as operaçoes a seguir: ");
            System.out.println("[1] - Buscar Farmaco");
            System.out.println("[2] - Realizar venda");
            System.out.println("[3] - Encerrar operaçoes");
            resp = Keyboard.readChar();

            switch (resp) {
                case '1':
                    System.out.println("Digite o nome: ");
                    nomePesquisa = Keyboard.readString();
                    System.out.println("Digite o codigo: ");
                    codigoPesquisa = Keyboard.readString();
                    for (Prateleira prat : prateleiras) {
                        farmaco = prat.pesquisaFarmaco(nomePesquisa, codigoPesquisa);
                        if (farmaco != null) {
                            System.out.println("Preço: " + farmaco.getPreco());
                        } else {
                            System.out.println("Farmaco nao encontrado.");
                        }
                    }
                    break;
                case '2':
                    System.out.println("Digite o nome: ");
                    nomePesquisa = Keyboard.readString();
                    System.out.println("Digite o codigo: ");
                    codigoPesquisa = Keyboard.readString();
                    for (Prateleira prat : prateleiras) {
                        farmaco = prat.pesquisaFarmaco(nomePesquisa, codigoPesquisa);
                        if (farmaco != null) {
                            System.out.println("Preço: " + farmaco.getPreco());
                            System.out.println("Digite a quantidade a ser adquirida (0 para cancelar compra): ");
                            quantidade = Keyboard.readInt();
                            farmaco.vender(quantidade);
                        } else {
                            System.out.println("Farmaco nao encontrado.");
                        }
                    }
                    break;
            }
        } while (resp != '3');
    }

    public void consultaFarmaco(Prateleira prateleira) {
        String nome, codigo;
        Farmaco farmaco;

        System.out.println("Digite o nome: ");
        nome = Keyboard.readString();
        System.out.println("Digite o codigo: ");
        codigo = Keyboard.readString();

        farmaco = prateleira.pesquisaFarmaco(nome, codigo);
        System.out.println("Farmaco encontrado: ");
        System.out.println("Nome: " + farmaco.getNome());
        System.out.println("Preço: " + farmaco.getPreco());
    }

    public String telefoneToString() {
        String telefone;
        Long tel_long;
        tel_long = super.getTelefone();
        telefone = tel_long.toString();
        return telefone;
    }

    public long codigoToLong() {
        String codigo;
        long codigo_long;
        codigo = super.getCodigo();
        codigo_long = Long.parseLong(codigo, 10);
        return codigo_long;
    }

}
