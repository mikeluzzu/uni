public class FirstApplication{

    public static void main(String[] args){
        
        for(int i=0;i<args.length; i++){
            switch (args[i]) {
                case "--no-action" -> System.exit(10);
                case "--command" -> {
                    System.out.print("java FirstApplication");
                    for(String toPrintArg: args)
                        System.out.print(" "+toPrintArg);
                    System.out.println("");
                }
                case "--convert" -> {
                    String binaryNumber = args[++i];
                    int n = 0;
                    int pow = 1;
                    for(int j = binaryNumber.length()-1; j>=0; j--){
                        if(binaryNumber.charAt(j) == '1')
                            n += pow;
                        pow *= 2; 
                    }
                    System.out.println("Il numero convertito è "+n);
                }
                case "--matrix" -> {
                    String word = args[++i];
                    String padding = args[++i];

                    char[][] matrix = new char[3][3];
                    for(int j = 0; j<3; j++){
                        matrix[j] = new char[3];
                        for(int k = 0; k<3; k++){
                            int index = (j*3)+k;
                            char currentChar = index >= word.length() ? padding.charAt(0) : word.charAt(index);
                            matrix[j][k] = currentChar;
                        }
                    }
                    for(char[] row : matrix){
                    System.out.print("| ");
                        for(char cell: row){
                            System.out.print(cell+" | ");
                        }
                        System.out.println("");

                    }
                    if(word.length()>9){
                        System.out.print("Caratteri rimanenti: "+word.substring(9,word.length()));
                    }
                }
                default -> System.out.println("Opzione non riconosciuta: "+args[i]);
            }
        }
        System.out.println("Bye Bye");
    }
}