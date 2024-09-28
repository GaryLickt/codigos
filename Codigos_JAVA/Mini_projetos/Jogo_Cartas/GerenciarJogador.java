package codigos.Codigos_JAVA.Mini_projetos.Jogo_Cartas;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.UUID;

public class GerenciarJogador {
  private static final int TAMANHO_NOME = 100;
  private static final int TAMANHO_SENHA = 50;
  private static final int TAMANHO_EMAIL = 100;

  public static Jogador cadastrarJogador(String nome, String senha, String email) {
    UUID uuid = UUID.randomUUID(); // Gerar UUID para o jogador

    try (DataOutputStream dos = new DataOutputStream(new FileOutputStream("playerdata.bin", true))) {
        // Escrevendo o UUID (16 bytes)
        dos.writeLong(uuid.getMostSignificantBits());
        dos.writeLong(uuid.getLeastSignificantBits());

        // Escrevendo nome, senha e email, ajustados ao tamanho fixo
        dos.write(fixarTamanhoString(nome, TAMANHO_NOME));
        dos.write(fixarTamanhoString(senha, TAMANHO_SENHA));
        dos.write(fixarTamanhoString(email, TAMANHO_EMAIL));

        System.out.println("Cadastro realizado com sucesso para o jogador: " + nome);
    } catch (IOException e) {
        System.err.println("Erro ao cadastrar jogador: " + e.getMessage());
    }

    Jogador jogador = new Jogador();
    jogador.setUuid(uuid);
    jogador.setNome(nome);
    jogador.setSenha(senha);
    jogador.setEmail(email);

    return jogador;
  }

  public static Jogador buscarJogadorPorDado(String dadoBusca, boolean isEmail) {
        try (DataInputStream dis = new DataInputStream(new FileInputStream("playerdata.bin"))) {
            while (dis.available() > 0) {
                // Lendo o UUID
                long msb = dis.readLong();
                long lsb = dis.readLong();
                UUID uuid = new UUID(msb, lsb);

                // Lendo nome, senha e email
                String nome = lerString(dis, TAMANHO_NOME);
                String senha = lerString(dis, TAMANHO_SENHA);
                String email = lerString(dis, TAMANHO_EMAIL);

                // Comparar dadoBusca com o dado correto
                if ((isEmail && email.trim().equals(dadoBusca)) || (!isEmail && senha.trim().equals(dadoBusca))) {
                    System.out.println("Jogador encontrado:");
                    System.out.println("UUID: " + uuid);
                    System.out.println("Nome: " + nome.trim());
                    System.out.println("Email: " + email.trim());
                    System.out.println("Senha: " + senha.trim());
                    
                    Jogador jogador = new Jogador();
                    jogador.setUuid(uuid);
                    jogador.setNome(nome);
                    jogador.setSenha(senha);
                    jogador.setEmail(email);

                    return jogador;
                }
            }
            System.out.println("Jogador não encontrado com o dado fornecido.");
        } catch (IOException e) {
            System.err.println("Erro ao buscar jogador: " + e.getMessage());
        }
        return null;
    }

  private static String lerString(DataInputStream dis, int tamanho) throws IOException {
      byte[] bytes = new byte[tamanho];
      dis.readFully(bytes);
      return new String(bytes).trim();
  }

  private static byte[] fixarTamanhoString(String str, int tamanho) {
    byte[] bytes = new byte[tamanho];
    byte[] stringBytes = str.getBytes();
    System.arraycopy(stringBytes, 0, bytes, 0, Math.min(stringBytes.length, tamanho));
    return bytes;
  }
}
