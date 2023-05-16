package Classes;

import javax.swing.JOptionPane;

public class Cartao {
	private int numUnico;
	private String titular;
	private int dataMes;
	private int dataAno;

	public Cartao() {
		super();
	}
	
	public Cartao(int numUnico, String titular, int dataMes, int dataAno) {
		super();
		this.numUnico = numUnico;
		this.titular = titular;
		this.dataMes = dataMes;
		this.dataAno = dataAno;
	}

	public int getNumUnico() {
		return numUnico;
	}

	public void setNumUnico(int numUnico) {
		this.numUnico = numUnico;
	}

	public String getTitular() {
		return titular;
	}

	public void setTitular(String titular) {
		this.titular = titular;
	}
	
	public int getDataMes() {
		return dataMes;
	}

	public void setDataMes(int dataMes) {
		this.dataMes = dataMes;
	}

	public int getDataAno() {
		return dataAno;
	}

	public void setDataAno(int dataAno) {
		this.dataAno = dataAno;
	}

	
	public void cadastrarCartao(Cartao cartao, Lista lista, No dado) {
		String leitura = JOptionPane.showInputDialog("Digite o número único do cartão22: ");
		int op = Integer.parseInt(leitura);
		cartao.setNumUnico(op);
		cartao.setTitular(JOptionPane.showInputDialog("Digite o nome completo: "));
		
		leitura = JOptionPane.showInputDialog("Digite o mês: ");
		op = Integer.parseInt(leitura);
		cartao.setDataMes(op);
		leitura = JOptionPane.showInputDialog("Digite o ano: ");
		op = Integer.parseInt(leitura);
		cartao.setDataAno(op);
		
		int hash = cartao.getNumUnico()%17;
		cartao.inserir(lista, hash, dado);
		}
		public int inserir(Lista lista, int hash, No dado){
			No novo = dado;
			if(novo == null) {
				novo.dado = dado;
				novo.proximo = null;
			}
			if(lista.elemento[hash] == null) {
				lista.elemento[hash] = novo;
			}
			else{
				novo.proximo = lista.elemento[hash];
				lista.elemento[hash] = novo;
			}
			lista.n+=1;
			return 1;
	}
}
