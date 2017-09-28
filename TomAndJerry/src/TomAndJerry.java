import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class TomAndJerry {

	public static void main(String[] args) {
		

		try {
			Scanner in;
			in = new Scanner(new File("input0.txt"));
			String[] firstLine;
			String Line;
			Line=in.nextLine();
			firstLine=Line.split(" ");
			int from;
			int to;
			int roomNumbers=Integer.parseInt(firstLine[0]);
			int homeOfTom=Integer.parseInt(firstLine[1])-1;
			int homeOfJerry=Integer.parseInt(firstLine[2])-1;
			Line=in.nextLine();
			String[] nextLine;
			ArrayList<ArrayList<Integer>> JerryGraph=new ArrayList<ArrayList<Integer>>();
			ArrayList<ArrayList<Integer>> TomGraph=new ArrayList<ArrayList<Integer>>();
			graphFiller(in, TomGraph);
			graphFiller(in, JerryGraph);
			in.close();

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
			
		} catch (FileNotFoundException e) {
			
			System.out.println("Not found the file");
		}


	}

	private static void graphFiller(Scanner in, ArrayList<ArrayList<Integer>> tomGraph) {
		String Line;
		String[] nextLine;
		int from;
		int to;
		Line = in.nextLine();
		nextLine = Line.split(" ");
		int j=-1;
		int var =Integer.parseInt(nextLine[0]) - 1;
		ArrayList<Integer> temp = new ArrayList<Integer>();
		while (nextLine[0] != "-1" || in.hasNext()){
			Line = in.nextLine();
			nextLine = Line.split(" ");
            from = Integer.parseInt(nextLine[0]) - 1;
            to = Integer.parseInt(nextLine[1]) - 1;
            if (from==var){
                j++;
            } else {
                j=0;
                tomGraph.add(temp);
                temp = new ArrayList<Integer>();
            }
            temp.add(j,to);
            var=from;
          }
	}

	private static void MB(ArrayList<ArrayList<Integer>> Graph,int[] rooms, int startcsúcs){
		rooms[startcsúcs]=1;
		for (int szomszéd:Graph.get(startcsúcs)){
			if (rooms[szomszéd]==0){
				MB(Graph,rooms,szomszéd);
			}
		}
	}
	private static void MB2(ArrayList<ArrayList<Integer>> Graph,int[] rooms, int startcsúcs,boolean talalkozás, boolean körséta,int jerry){
		if (talalkozás && körséta == false ){
			rooms[startcsúcs]=2;
			for (int szomszéd:Graph.get(startcsúcs)){
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
