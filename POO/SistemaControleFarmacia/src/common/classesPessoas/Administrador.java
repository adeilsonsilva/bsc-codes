package common.classesPessoas;

import common.classesProdutos.Farmaco;
import common.classesProdutos.Prateleira;
import inOut.Keyboard;
import java.util.ArrayList;

public class Administrador extends Funcionario {
    
    private String email;
    private String senha;
    
    public Administrador(String nome, String codigo, double salario, String escolaridade, String dataAdmissao, String endereco, String CPF, long telefone, String email, String senha) {
        super(nome, codigo, salario, escolaridade, dataAdmissao, endereco, CPF, telefone);
        this.email = email;
        this.senha = senha;
    }
    
    public String getEmail() {
        return this.email;
    }
    
    public void setEmail(String email) {
        this.email = email;
    }
    
    public String getSenha() {
        return this.senha;
    }
    
    public void setSenha(String senha) {
        this.senha = senha;
    }
    
    public static Administrador cadastraAdministrador() {
        String nome, codigo, endereco, CPF, escolaridade, dataAdmissao, email, senha;
        double salario;
        long telefone;
        Administrador admin;
        
        System.out.println("Digite o nome: ");
        nome = Keyboard.readString();
        System.out.println("Digite o Código: ");
        codigo = Keyboard.readString();
        System.out.println("Digite o Endereco: ");
        endereco = Keyboard.readString();
        System.out.println("Digite o CPF: ");
        CPF = Keyboard.readString();
        System.out.println("Digite a escolaridade: ");
        escolaridade = Keyboard.readString();
        System.out.println("Digite a data de admissao: ");
        dataAdmissao = Keyboard.readString();
        System.out.println("Digite o salario: ");
        salario = Keyboard.readDouble();
        System.out.println("Digite o telefone: ");
        telefone = Keyboard.readLong();
        System.out.println("Digite o email: ");
        email = Keyboard.readString();
        System.out.println("Digite a senha: ");
        senha = Keyboard.readString();
        
        admin = new Administrador(nome, codigo, salario, escolaridade, dataAdmissao, endereco, CPF, telefone, email, senha);
        return admin;
    }
    
    public static Funcionario cadastraFuncionario() {
        String nome, codigo, endereco, CPF, escolaridade, dataAdmissao;
        double salario;
        long telefone;
        Funcionario funcionario;
        
        System.out.println("Digite o nome: ");
        nome = Keyboard.readString();
        System.out.println("Digite o Código: ");
        codigo = Keyboard.readString();
        System.out.println("Digite o Endereco: ");
        endereco = Keyboard.readString();
        System.out.println("Digite o CPF: ");
        CPF = Keyboard.readString();
        System.out.println("Digite a escolaridade: ");
        escolaridade = Keyboard.readString();
        System.out.println("Digite a data de admissao: ");
        dataAdmissao = Keyboard.readString();
        System.out.println("Digite o salario: ");
        salario = Keyboard.readDouble();
        System.out.println("Digite o telefone: ");
        telefone = Keyboard.readLong();
        System.out.println("Digite o email: ");
        
        funcionario = new Funcionario(nome, codigo, salario, escolaridade, dataAdmissao, endereco, CPF, telefone);
        return funcionario;
    }
    
    public boolean Login(String email, String senha) throws AdminLoginException {
        if ((email.isEmpty()) || (senha.isEmpty())) {
            throw new AdminLoginException("E-mail ou senha nao cadastrado.");
        }        
        return (this.email.equals(email)) && (this.senha.equals(senha));
    }
    
    public void adminLogado() {
        ArrayList<Prateleira> prateleiras = new ArrayList<>();
        char resp;
        int quantidade;
        String nomePesquisa;
        String codigoPesquisa;
        Farmaco farmaco;
        
        super.logado();
        for (int i = 1; i <= Prateleira.qtdMaxPrateleiras; i++) {
            prateleiras.add(i, new Prateleira());
        }
        System.out.println("Bem vindo " + this.getNome() + "!!");
        do {            
            System.out.println("Escolha as operaçoes a seguir: ");
            System.out.println("[1] - Cadastrar Funcionarios");
            System.out.println("[2] - Cadastrar Farmaco");
            System.out.println("[3] - Buscar Farmaco");
            System.out.println("[4] - Realizar venda");
            System.out.println("[5] - Encerrar operaçoes");
            resp = Keyboard.readChar();
            
            switch (resp) {
                case '1':
                    Administrador.cadastraFuncionario();
                    break;
                case '2':
                    farmaco = Administrador.cadastraFarmaco();
                    for (Prateleira prat : prateleiras) {
                        if (prat.adicionaFarmaco(farmaco)) {
                            break;
                        }
                    }
                    break;
                case '3':
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
                case '4':
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
        } while (resp != '5');
    }
    
    public static Farmaco cadastraFarmaco() {
        String sintomas;
        String efeitos;
        String nome;
        String codigo;
        String tarja;
        String fabricante;
        double preco;        
        int quantidade;
        
        System.out.println("Digite os sintomas: ");
        sintomas = Keyboard.readString();
        System.out.println("Digite os efeitos: ");
        efeitos = Keyboard.readString();
        System.out.println("Digite o nome: ");
        nome = Keyboard.readString();
        System.out.println("Digite o codigo: ");
        codigo = Keyboard.readString();
        System.out.println("Digite a tarja: ");
        tarja = Keyboard.readString();
        System.out.println("Digite o fabricante: ");
        fabricante = Keyboard.readString();
        System.out.println("Digite o preço: ");
        preco = Keyboard.readDouble();
        System.out.println("Digite a quantidade: ");
        quantidade = Keyboard.readInt();
        
        Farmaco farmaco = new Farmaco(sintomas, efeitos, nome, codigo, tarja, fabricante, preco, quantidade);
        return farmaco;        
    }
    
    public void removeFuncionario() {
        
    }
    
    public void removeFarmaco() {
        
    }
    
}
