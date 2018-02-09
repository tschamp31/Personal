public class Wee5Q1TylerChampagne
{                
        static class numberList 
        {
            int List[];
            int currentCount;
            int maxSize;
            

            public numberList()
            {
                List = new int[10];
                maxSize = 10;
                currentCount = -1;
            }
                /** initializes the list to contain a maximum of 10 items **/
            public numberList(int size)
            {
                List = new int[size];
                maxSize = size;
                currentCount = -1;
            }
                /** initializes the list to contain a maximum of size items **/
            public void insert(int newNumber)
            {
                if(currentCount + 1 < maxSize)
                {
                    currentCount++;
                    int i,j, temp;
                    List[currentCount] = newNumber;
                    for (i = 1; i < List.length; i++)
                    {
                           temp = List[i];
                           for(j = i - 1; (j >= 0) && (List[j] < temp); j--)
                          {
                                 List[j+1] = List[j];
                          }
                         List[j+1] = temp;
                    }
                }
                else
                {
                    System.out.println("Error 1: List is Full");
                }
            }
                /** insert newNumber into the list in sorted order, if the list
                    is full do nothing and discard newNumber **/
            public boolean isFull()
            {
                return maxSize == currentCount;
            }
                /** return true if the list is full **/
            public boolean isEmpty()
            {
                return currentCount == -1;
            }
                /** return true if the list is empty **/
            public void printList()
            {
                while(currentCount >= 0)
            {
                System.out.print(List[currentCount] + " ");
                currentCount--;
            }
            System.out.println();
            }
                /** print the entire contents of the list **/
        }



        static class stringList 
        {
            String List[];
            int currentCount;
            int maxSize;
                    
            public stringList()
            {
                List = new String[10];
                maxSize = 10;
                currentCount = -1;
            }
                /** initializes the list to contain a maximum of 10 items **/
            public stringList(int size)
            {
                List = new String[size];
                maxSize = size;
                currentCount = -1;
            }
                /** initializes the list to contain a maximum of size items **/
            public void insert(String newString)
            {
                if(currentCount + 1 < maxSize)
                {
                    currentCount++;
                    List[currentCount] = newString;            
                }
                else
                {
                    System.out.println("Error 1: List is Full");
                }
            }
                /** insert newString into the list into the next available position, if
                    the list is full do nothing and discard newString **/
            public boolean isFull()
            {
                return maxSize == currentCount;
            }
                /** return true if the list is full **/
            public boolean isEmpty()
            {
                return currentCount == -1;
            }
                /** return true if the list is empty **/
            public void sortList()
            {
                int i, j, counter;
                String temp;
                counter = currentCount + 1;
                for (i = 0; i < counter; i++)
                {
                      temp = List[i];
                      for(j = i - 1; (j >= 0) && (List[j].compareTo(temp) < temp.compareTo(List[j])); j--)
                      {
                             List[j+1] = List[j];
                      }
                     List[j+1] = temp;
                }
            }
                /** sort the contents of the list **/
            public void printList()
            {
                int counter;
                counter = currentCount;
                while(counter >= 0)
            {
                System.out.println(counter + ":" + List[counter]);
                counter--;
            }
            }
        }
                /** print the entire contents of the list **/


        static class studentType 
        {
            String Fname;
            String Lname;
            int Score;
            

            public studentType()
            {
                Fname = "";
                Lname = "";
                Score = 0;
            }
                /** initializes a studentType object to a score of
                    zero and Fname, Lname to empty strings **/

            public studentType(String fname, String lname)
            {
                Fname = fname;
                Lname = lname;
                Score = 0;
            }
                /** initializes a studentType object to a score of
                    zero and Fname, Lname to the specified values **/

            public void setFname(String fname)
            {
                Fname = fname;
            }
            public void setLname(String lname)
            {
                Lname = lname;
            }
            public void setScore(int score)
            {
                Score = score;
            }

            public String getFname()
            {
                return Fname;
            }
            public String getLname()
            {
                return Lname;
            }
            public int getScore()
            {
                return Score;
            }

            public String toString()
            {
                return Lname + ", " + Fname + ": " + Score;    
            }
                /** returns string as: "Lname, Fname: score" **/
        }

        static class studentListType 
        {
            String Fname[];
            String Lname[];
            int Score[];
            int maxSize, currentCount;
            

            public studentListType()
            {
                Fname = new String[10];
                Lname = new String[10];
                Score = new int[10];
                maxSize = 10;
                currentCount = -1;
            }

            public studentListType(int size)
            {
                Fname = new String[size];
                Lname = new String[size];
                Score = new int[size];
                maxSize = 10;
                currentCount = -1;
            }

            public void insert(String newlname,String newfname,int newscore)
            {
                if(currentCount + 1 < maxSize)
                {
                    currentCount++;
                    Lname[currentCount] = newlname;
                    Fname[currentCount] = newfname;
                    Score[currentCount] = newscore;
                }
                else
                {
                    System.out.println("Error 1: List is Full");
                }
            }

            public boolean isFull()
            {
                return currentCount == maxSize;
            }

            public boolean isEmpty()
            {
                return currentCount == -1;
            }

            public void sortList(int option)
            {
                int j,i,counter,temp1;
                String temp2,temp3;
                switch(option)
                {
                    case 1:
                                counter = currentCount + 1;
                                for (i = 0; i < counter; i++)
                                {
                                       temp1 = Score[i];
                                       temp2 = Fname[i];
                                       temp3 = Lname[i];
                                      for(j = i - 1; (j >= 0) && (Fname[j].compareTo(temp2) > temp2.compareTo(Fname[j])); j--)
                                      {
                                             Fname[j+1] = Fname[j];
                                             Lname[j+1] = Lname[j];
                                             Score[j+1] = Score[j];
                                      }
                                     Score[j+1] = temp1;
                                     Fname[j+1] = temp2;
                                     Lname[j+1] = temp3;
                                }
                                break;

                    case 2: 
                                counter = currentCount + 1;
                                for (i = 0; i < counter; i++)
                                {
                                       temp1 = Score[i];
                                       temp2 = Fname[i];
                                       temp3 = Lname[i];
                                      for(j = i - 1; (j >= 0) && (Lname[j].compareTo(temp3) > temp3.compareTo(Lname[j])); j--)
                                      {
                                             Fname[j+1] = Fname[j];
                                             Lname[j+1] = Lname[j];
                                             Score[j+1] = Score[j];
                                      }
                                     Score[j+1] = temp1;
                                     Fname[j+1] = temp2;
                                     Lname[j+1] = temp3;
                                }
                                break;

                    case 3:
                                counter = currentCount + 1;
                                for (i = 1; i < counter; i++)
                                {
                                       temp1 = Score[i];
                                       temp2 = Fname[i];
                                       temp3 = Lname[i];
                                       for(j = i - 1; (j >= 0) && (Score[j] < temp1); j--)
                                      {
                                             Fname[j+1] = Fname[j];
                                             Lname[j+1] = Lname[j];
                                             Score[j+1] = Score[j];
                                      }
                                     Score[j+1] = temp1;
                                     Fname[j+1] = temp2;
                                     Lname[j+1] = temp3;
                                }
                                break;
                }
            }
            public void printList()
            {
                int counter;
                counter = currentCount;
                while(counter >= 0)
            {
                System.out.println(Lname[counter] + ", " + Fname[counter] + ": " + Score[counter]);
                counter--;
            }
            }

        }                

        public static void main(String []args)
        {
        }
    }