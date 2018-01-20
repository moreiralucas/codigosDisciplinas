package cirurgia;
import pessoas.*;
import java.util.ArrayList;
public class SalaCirurgia{
    private boolean statusOcupada;
    private int idSala;
    private int last;
    private ArrayList<FormularioDeCirurgia> cirurgias = new ArrayList<FormularioDeCirurgia>();
    public SalaCirurgia(int idSala){
        this.idSala=idSala;
    }
    
    public int getIdSala(){
        return idSala;
    }
    
    public void planejarCirurgia(int idCirurgia,String tipoCirurgia, Paciente paciente, double valorTotal){
        if (statusOcupada==false){
            cirurgias.add(new FormularioDeCirurgia(idCirurgia,tipoCirurgia,paciente,valorTotal));
            statusOcupada=true;
            System.out.println("Cirurgia planejada com sucesso!");
        }else
            System.out.println("Sala ocupada no momento, finalize ou cancele a cirurgia.");
        last=idCirurgia;
    }
    
    public void inserirProfissionalDeSaudeEmCirurgia(Funcionario prof){
        if (prof instanceof ProfissionalSaude){
                cirurgias.get(last).inserirProfissionalDeSaudeEmCirurgia(prof);
                System.out.println(prof.toString() + "\nInserido com sucesso!");
            }
    }
    
    public void finalizarCirurgia(){
        if (statusOcupada!=false){
            cirurgias.get(last).finalizarCirurgia();
            System.out.println("Cirgia finalizada com sucesso!");
        }else
            System.out.println("Não há cirurgia ocorrendo nesta sala!");
        statusOcupada=false;
    }
    
    public void cancelarCirurgia(){
        if (statusOcupada!=false){
            cirurgias.get(last).cancelarCirurgia();
            System.out.println("Cirgia cancelada!");
        }else
            System.out.println("Não há cirurgia ocorrendo nesta sala!");
        statusOcupada=false;
    }
}
