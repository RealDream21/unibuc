package cabinet.domain;

import java.io.IOException;
import java.util.*;

import static java.util.Collections.sort;

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
        nume = readNume(input);
        System.out.println("Dati email-ul clientului:");
        email = readEmail(input);
        System.out.println("Dati numarul de telefon al clientului:");
        numarTelefon = readNumarTelefon(input);

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
        nume = readNume(input);
        System.out.println("Dati email-ul medicului:");
        email = readEmail(input);
        System.out.println("Dati numarul de telefon al medicului:");
        numarTelefon = readNumarTelefon(input);

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

    public final void addProgramare()
    {
        Scanner input = new Scanner(System.in);
        System.out.println("Alege clientul(-1 pentru ultimul client adaugat): ");
        for(int i = 0; i < clienti.size(); i++)
        {
            System.out.println(i + ". " + clienti.get(i));
        }
        int indexClient = input.nextInt();
        if(indexClient == -1)
            indexClient = clienti.size() - 1;
        if(indexClient < 0 || indexClient > clienti.size() - 1)
            throw new RuntimeException("Indexul clientului nu este in range-ul listei de clienti");

        System.out.println("Alege medicul(-1 pentru ultimul medic adaugat): ");
        for(int i = 0; i < medici.size(); i++)
        {
            System.out.println(i + ". " + medici.get(i));
        }
        int indexMedic = input.nextInt();
        if(indexMedic == -1)
            indexMedic = medici.size() - 1;
        if(indexMedic < 0 || indexMedic > medici.size() - 1)
            throw new RuntimeException("Indexul medicului nu este in range-ul listei de medici");

        Date data = new Date(inputDataAsLong(input));

        System.out.println("De ce tip este programarea?\n1.Consult\n2.Urgenta");
        int tipProgramare = input.nextInt();
        if(tipProgramare == 1)
        {
            programari.add(new ProgramareConsult(data, medici.get(indexMedic), clienti.get(indexClient)));
        }
        else if(tipProgramare == 2)
        {
            System.out.println("De la 0 la " + ProgramareUrgenta.getURGENTA_MAXIMA() + " cat de urgenta este situatia?");
            int gradUrgenta = input.nextInt();
            if(gradUrgenta < 0 || gradUrgenta > ProgramareUrgenta.getURGENTA_MAXIMA())
                throw new RuntimeException("Gradul urgentei nu este bun");
            programari.add(new ProgramareUrgenta(data, medici.get(indexMedic), clienti.get(indexClient), gradUrgenta));
        }
        else{
            throw new RuntimeException("Nu exista acest tip de programare");
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

    public final List<Programare> getProgramari()
    {
        return List.copyOf(programari);
    }

    public final List<Programare> getProgramariSortate()
    {
        List<Programare> aux = List.copyOf(programari);
        Collections.sort(aux);
        return List.copyOf(aux);
    }


    private static String readNume(Scanner input){
        String nume;
        nume = input.nextLine();
        nume = nume.strip();
        return nume;
    }

    private static String readEmail(Scanner input){
        String email;
        email = input.nextLine();
        email = email.strip();
        return email;
    }

    private static String readNumarTelefon(Scanner input){
        String numarTelefon;
        numarTelefon = input.nextLine();
        numarTelefon = numarTelefon.strip();
        return numarTelefon;
    }

    private static long inputDataAsLong(Scanner input){
        GregorianCalendar gregorianCalendar = new GregorianCalendar();
        System.out.println("In ce an este programarea?");
        int an = input.nextInt();
        if(an < 2024)
            throw new RuntimeException("Data nu poate fi trecuta in trecut");
        if(an > 2050)
            throw new RuntimeException("Data nu poate fi trecuta atat de in viitor");

        System.out.println("In ce luna este programarea?");
        int luna = input.nextInt();
        if(luna < 0)
            throw new RuntimeException("Data nu poate fi negativa");
        if(luna > 12)
            throw new RuntimeException("Data nu poate fi > 12");

        System.out.println("In ce zi este programarea?");
        int zi = input.nextInt();
        if(zi < 0)
            throw new RuntimeException("Ziua nu poate fi negativa");
        if(zi > 31)
            throw new RuntimeException("Ziua nu poate fi > 31");

        gregorianCalendar.set(an, luna, zi);

        return gregorianCalendar.getTimeInMillis();
    }

}
