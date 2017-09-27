import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class TomAndJerry {

	public static void main(String[] args) {
		
		Scanner in;
		int[][] TomGraph=null;
		int[][] JerryGraph=null;
		int roomNumbers=0;
		int homeOfTom=0;
		int homeOfJerry=0;
		try {
			in = new Scanner(new File("input0.txt"));
			String[] firstLine;
			String Line;
			Line=in.nextLine();
			firstLine=Line.split(" ");
			int from;
			int to;
			int length;
			roomNumbers=Integer.parseInt(firstLine[0]);
			homeOfTom=Integer.parseInt(firstLine[1])-1;
			homeOfJerry=Integer.parseInt(firstLine[2])-1;
			Line=in.nextLine();
			String[] nextLine;

			while (Line != "-1 -1") {
				nextLine = Line.split(" ");
				from = Integer.parseInt(firstLine[0]) - 1;
				to = Integer.parseInt(firstLine[1]) - 1;
				length = TomGraph[from].length;
				TomGraph[from][length-1] = to;
				Line = in.nextLine();
			}
			while (in.hasNext()){
				Line=in.nextLine();
				nextLine=Line.split(" ");
				from=Integer.parseInt(firstLine[0])-1;
				to=Integer.parseInt(firstLine[1])-1;
				length=JerryGraph[from].length;
				JerryGraph[from][length-1]=to;
			}

			in.close();
			
		} catch (FileNotFoundException e) {
			
			e.printStackTrace();
		}
		int[] rooms = new int[roomNumbers];
		for ( int room :rooms){
			room = 0;
		}
		MB(TomGraph,rooms,homeOfTom);
		if (rooms[homeOfJerry]==1){
			System.out.println("true and false");
		}else{
			boolean talalkozás=false;
			boolean körséta=false;
			MB2(JerryGraph,rooms,homeOfJerry,talalkozás,körséta,homeOfJerry);
			System.out.println(talalkozás+" and "+körséta);
		}

	}
	public static void MB(int[][] Graph,int[] rooms, int startcsúcs){
		rooms[startcsúcs]=1;
		for (int szomszéd:Graph[startcsúcs]){
			if (rooms[szomszéd]==0){
				MB(Graph,rooms,szomszéd);
			}
		}
	}
	public static void MB2(int[][] Graph,int[] rooms, int startcsúcs,boolean talalkozás, boolean körséta,int jerry){
		if (talalkozás && körséta == false ){
			rooms[startcsúcs]=2;
			for (int szomszéd:Graph[startcsúcs]){
				if (rooms[szomszéd]==0){
					MB2(Graph,rooms,szomszéd,talalkozás,körséta,jerry);
				}else if(rooms[szomszéd]==1){
					talalkozás=true;
				}else if(rooms[szomszéd]==2){
					if (startcsúcs==jerry && szomszéd!=jerry){
						körséta=true;
					}
				}
			}
		}
	}


}
