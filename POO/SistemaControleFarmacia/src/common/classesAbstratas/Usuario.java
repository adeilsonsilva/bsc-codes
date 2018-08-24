package common.classesAbstratas;

public abstract class Usuario{
	
	private String nome;
	private String codigo;
	private String endereco;
	private long telefone;
	
	public Usuario(String nome, String codigo, String endereco, long telefone) {
		this.nome = nome;
		this.codigo = codigo;
		this.endereco = endereco;
		this.telefone = telefone;
	}
	
	public abstract String telefoneToString();
	public abstract long codigoToLong();
	
	public String getEndereco() {
		return this.endereco;
	}
	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}
	public long getTelefone() {
		return this.telefone;
	}
	public void setTelefone(long telefone) {
		this.telefone = telefone;
	}
	public String getNome() {
		return this.nome;
	}
	public void setNome(String nome) {
		this.nome = nome;
	}
	public String getCodigo() {
		return this.codigo;
	}
	public void setCodigo(String codigo) {
		this.codigo = codigo;
	}
}
