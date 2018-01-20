package pessoas;

public class PacientePrioritario extends Paciente{
    private String motivoPrioridade;
    public PacientePrioritario(String nome, int rg, int idade, String motivo, int idProntuario){
        super(nome, rg, idade, idProntuario);
        this.motivoPrioridade = motivo;
    }
}
