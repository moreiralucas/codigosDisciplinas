package pessoas;

import java.util.Calendar;
public abstract class Pessoa{
    private String nome;
    private int rg;
    private int idade;
    
    public Pessoa(String nome, int rg, int idade){
        this.nome = nome;
        this.rg = rg;
        this.idade = idade;
    }
    
    public String toString() {
        return "Nome: " + nome + "\nRG: " + rg  + "\nIdade: " + idade + "\n";
    }

    public String getNome() {
        return nome;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public int getRg() {
        return rg;
    }

    public void setRg(int rg) {
        this.rg = rg;
    }

    public int getIdade() {
        return idade;
    }

    public void setIdade(int idade) {
        if (idade < 0)
            System.out.println("Idade inválida\nTente novamente!");
        this.idade = idade;
    }
    
    
}
