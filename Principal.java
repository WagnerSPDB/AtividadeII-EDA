package Classes;
public class Principal {
	
	int criar(Lista lista){
		int i=0;
		for(i=0;i<17;i++) {
			lista.elemento[i] = null;
		}
		lista.n=0;
		return 1;
	}

	public static void main(String[] args) {
		Principal principal = new Principal();
		Lista lista = new Lista();
		principal.criar(lista);
		Usuario usuario = new Usuario();
		//usuario.cadastrarUsuario(usuario);
		
		Cartao cartao = new Cartao();
		cartao.cadastrarCartao(cartao, lista, null);
	}
}

class No {
	Cartao cartao;
	No dado = new No();
	No proximo;
}

class Lista{
    No elemento[] = new No[17];
    int n;
}