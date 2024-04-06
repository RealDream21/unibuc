package cabinet.domain;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

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
    public final void addClient() throws IOException, RuntimeException {
        //daca am vreo eraore => false(asta pentru viitor cand fac erori)
        //frumos ar fi sa fac o persoanaBuilder dar deja e prea mult
        Scanner input = new Scanner(System.in);
        String nume, email, numarTelefon;
        System.out.println("Dati numele clientului");
        nume = input.nextLine();
        nume = nume.strip();
        System.out.println("Dati email-ul clientului:");
        email = input.nextLine();
        email = email.strip();
        System.out.println("Dati numarul de telefon al clientului:");
        numarTelefon = input.nextLine();
        numarTelefon = numarTelefon.strip();

        Client client = new Client(nume, email, numarTelefon);
        if(client != null)
        {
            clienti.add(new Client(nume, email, numarTelefon));
        }
        else{
            throw new RuntimeException("EROARE LA CREAREA CLIENTULUI");
        }
    }

    public final void addMedic() throws IOException, RuntimeException {
        Scanner input = new Scanner(System.in);
        String nume, email, numarTelefon;
        System.out.println("Dati numele medicului");
        nume = input.nextLine();
        nume = nume.strip();
        System.out.println("Dati email-ul medicului:");
        email = input.nextLine();
        email = email.strip();
        System.out.println("Dati numarul de telefon al medicului:");
        numarTelefon = input.nextLine();
        numarTelefon = numarTelefon.strip();
        System.out.println("NUMARUL DE TELEFON ESTE: " + numarTelefon);

        System.out.println("Medicul este specialist sau generalist?\n1.Specialist\n2.Generalist");
        int tip = input.nextInt();
        if(tip == 1)
        {
            System.out.println("In ce se specializeaza?\n");
            Specializare[] specializari = Arrays.copyOf(Specializare.values(), Specializare.values().length);
            for(int i = 0; i < specializari.length; i++)
            {
                System.out.println(i + ". " + specializari[i]);
            }
            int indexSpec = input.nextInt();
            if(indexSpec >= 0 && indexSpec < specializari.length){
                Specializare spec = specializari[indexSpec];
                medici.add(new MedicSpecialist(nume, email, numarTelefon, spec));
            }
            else {
                throw new RuntimeException("Indexul accesat nu este in range");
            }
        } else if (tip == 2){
            medici.add(new MedicGeneralist(nume, email, numarTelefon));
        } else{
            throw new IOException("Nu exista acest tip de medic");
        }
    }

    public final List<Client> getClienti()
    {
        return List.copyOf(clienti);
    }

    public final List<Medic> getMedici()
    {
        return List.copyOf(medici);
    }

}
