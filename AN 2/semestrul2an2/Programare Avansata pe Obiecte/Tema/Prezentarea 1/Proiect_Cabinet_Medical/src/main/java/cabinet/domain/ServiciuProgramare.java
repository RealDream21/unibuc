package cabinet.domain;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public abstract class ServiciuProgramare{
    //aici implementez feature-urile pentru serviciul de programare
    private List<Client> clienti;
    private List<Medic> medici;
    private List<Programare> programari;

    protected ServiciuProgramare(){
        clienti = new ArrayList<Client>();
        medici = new ArrayList<Medic>();
        programari = new ArrayList<Programare>();
    }
    public final boolean addClient() throws IOException {
        //daca am vreo eraore => false(asta pentru viitor cand fac erori)
        //frumos ar fi sa fac o persoanaBuilder dar deja e prea mult
        String nume, email, numarTelefon;
        System.out.println("Dati numele clientului");
        byte[] b = new byte[255];
        System.in.read(b);
        nume = new String(b);
        nume = nume.strip();
        System.out.println("Dati email-ul clientului:");
        System.in.read(b);
        email = new String(b);
        email = email.strip();
        System.out.println("Dati numarul de telefon al clientului:");
        System.in.read(b);
        numarTelefon = new String(b);
        numarTelefon = numarTelefon.strip();

        Client client = new Client(nume, email, numarTelefon);
        if(client != null)
        {
            clienti.add(new Client(nume, email, numarTelefon));
        }
        else{
            System.out.println("EROARE LA CLIENT");
        }
        return true;
    }

    public final List<Client> getClienti()
    {
        return List.copyOf(clienti);
    }

}
