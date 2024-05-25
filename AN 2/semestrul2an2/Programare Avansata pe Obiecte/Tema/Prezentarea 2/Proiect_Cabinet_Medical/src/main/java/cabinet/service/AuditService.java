package cabinet.service;

import java.io.File;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.time.Instant;
import java.util.Date;
import java.util.Random;

public class AuditService {

    public static AuditService instance;

    private AuditService(){}

    public static AuditService getInstance(){
        if(instance == null) {
            instance = new AuditService();
        }
        return instance;
    }


    public void writeLine(String filePath, String line)
    {
        try(RandomAccessFile randomAccessFile = new RandomAccessFile(filePath, "rw")){
            File file = new File(filePath);
            randomAccessFile.seek(file.length());
            randomAccessFile.write("\n".getBytes());
            Date dataActuala = new Date(Instant.now().toEpochMilli());
            String linieDeScris = dataActuala.toString() +"," + line;
            randomAccessFile.write(linieDeScris.getBytes());
        }catch(IOException e){
            e.printStackTrace();
        }
    }

}
