package Classes;

import javax.swing.JOptionPane;

public class Usuario extends Cartao{
	private String CPF;
	private String nomeCompleto;
	private String endereco;
	
	private Cartao cartao;
	
	public Usuario(int numUnico, String titular, int dataMes, int dataAno) {
		super(numUnico, titular, dataMes, dataAno);
	}

	public Usuario() {
	}

	public String getCPF() {
		return CPF;
	}

	public void setCPF(String cPF) {
		CPF = cPF;
	}

	public String getNomeCompleto() {
		return nomeCompleto;
	}

	public void setNomeCompleto(String nomeCompleto) {
		this.nomeCompleto = nomeCompleto;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		this.endereco = endereco;
	}

	public Cartao getCartao() {
		return cartao;
	}

	public void setCartao(Cartao cartao) {
		this.cartao = cartao;
	}
	
	public void cadastrarUsuario(Usuario usuario) {
		usuario.setNomeCompleto(JOptionPane.showInputDialog("Digite o nome completo: "));
		usuario.setCPF(JOptionPane.showInputDialog("Digite o CPF: "));
		usuario.setEndereco(JOptionPane.showInputDialog("Digite o endereco: "));
		
		Cartao cartao = new Cartao();
		String leitura = JOptionPane.showInputDialog("Digite o número único do cartão: ");
		int op = Integer.parseInt(leitura);
		//if(op == existe) {
			cartao.setNumUnico(op);
		//}
		
	}
}
