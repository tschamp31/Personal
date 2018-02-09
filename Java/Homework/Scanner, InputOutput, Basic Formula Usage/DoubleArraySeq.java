
public class DoubleArraySeq implements Cloneable
{
   private double[ ] data;
   private int manyItems;
   private int curretNumber; 

   /**
   * Initialize an empty sequence with an initial capacity of 10. Note that the addAfter and addBefore methods work efficiently (without needing more memory) until the capacity is reached.
   * @precondition
   *   This sequence is empty and has an initial capacity of 10.
   * @exception OutofMemoryError Indicates insuffiecnt memory for new double [10].   
   **/    

   public DoubleArraySeq( )
   {
      try
      {
         data = new double[10];
      }
      catch(OutOfMemoryError E)
      {
         System.out.println("System out of memory.");
      }
   }

   /**
   * Initialize an empty sequence with a specified initial capacity. Note that the addAfter and addBefore methods work efficiently (without adding more memory) until this capacity is reached.
   * @param initialCapacity- the initial capacity of this sequence\
   * @precondition initalCapacity is non-negative.
   * @postcondition This sequence is empty and has the given initial capacity.
   * @exception IllegalArgumentException Indicates that initialCapacity is negative.
   * @exception OutofMemoryError Indicates insufficient memory for new double [initialCapacity].
   **/

   public DoubleArraySeq(int initialCapacity)
   {
      try
      {
         if(initialCapacity < 0)
         {
            System.out.println("ERROR: Initial capacity can not be less than 0");  
         }
         else
         {
            data = new double[initialCapacity];
         }
      }
      catch(OutOfMemoryError E)
      {
         System.out.println("System out of memory.");
      }
   }

   /**
   * Adds a new element to this sequence, either before or after the current element. If this new element would take this sequence beyond its current capacity, then the capacity is increased before adding the new element.
   * @param element – the new element that is being added 
   * @postcondition A new copy of the element has been added to this sequence. If there was a current element, the addAfter places the new element after the current element, 
   * and addBefore places the new element before the current element. 
   * If there was no current element, then addAfter places the new element at the end of this sequence, 
   * and addBefore places the new element at the front of this sequence. 
   * In all cases, the new element becomes the new current element of this sequence.
   * @exception OutOfMemoryError Indicates insufficient memory to increase the size of this sequence.
   * @note An attempt to increase the capacity beyond Interger.MAX_VALUE will cause this sequence to fail with an arithmetic overflow.
   **/

   public void addAfter(int element)
   {
      try
      {
         if(curretNumber + 1 < this.data.length)
         {
            this.data[curretNumber + 1] = element;
         }
      }
      catch(OutOfMemoryError E)
      {
         System.out.println("ERROR: System out of memory.");
      }
      catch(IllegalStateException E)
      {
         System.out.println("ERROR: There is no current element.");
      }
   }

   /**
   * Adds a new element to this sequence, either before or after the current element. If this new element would take this sequence beyond its current capacity, then the capacity is increased before adding the new element.
   * @param element – the new element that is being added 
   * @postcondition A new copy of the element has been added to this sequence. If there was a current element, the addAfter places the new element after the current element, 
   * and addBefore places the new element before the current element. 
   * If there was no current element, then addAfter places the new element at the end of this sequence, 
   * and addBefore places the new element at the front of this sequence. 
   * In all cases, the new element becomes the new current element of this sequence.
   * @exception OutOfMemoryError Indicates insufficient memory to increase the size of this sequence.
   * @note An attempt to increase the capacity beyond Interger.MAX_VALUE will cause this sequence to fail with an arithmetic overflow.
   **/

   public void addBefore(int element)
   {
      try
      {
         if(curretNumber - 1 < this.data.length)
         {
            this.data[curretNumber - 1] = element;
         }
      }
      catch(OutOfMemoryError E)
      {
         System.out.println("ERROR: System out of memory.");
      }
   }

   /**
   * Place the contents of another sequence at the end of this sequence.
   * @param addend – a sequence whose contents will be placed at the end of this sequence.
   * @precondition The parameters, addend, is not null. 
   * @postcondition The element from addend have been placed at the end of this sequence. The current element of this sequence remains where it was, and the addend is also unchanged.
   * @exception NullPointerException Indicates that addend is null.
   * @exception OutOfMemoryError Indicates insufficient memory to increase the size of this sequence.
   * @note An attempt to increase the capacity beyond Interger.MAX_VALUE will cause this sequence to fail with an arithmetic overflow.
   **/

   public void addAll(DoubleArraySeq addend)
   {
      try
      {
         if(addend != null)
         {
            this.data = new double[this.data.length + addend.size()];
            System.arraycopy(this.data, 0, this.data, 0, addend.size());
            System.arraycopy(addend, 0, this.data, this.data.length, addend.size());
         }
      }
      catch(OutOfMemoryError E)
      {
         System.out.println("ERROR: System out of memory.");
      }
      catch(NullPointerException E)
      {
         System.out.println("ERROR: Array is null");
      }
   
   }   
   
   /**
   * Move forward so that the current element is now the next element in this sequence.
   * @precondition isCurrent( ) returns true
   * @postcondition If the current element was already the end element of this sequence (with nothing after it), then there is no longer any current element. Otherwise, the new element is the element immediately after the original current element
   * @exception IllegalStateException Indicates that there is no current element, so advance may not be called.
   **/

   public void advance( )
   {
      try
      {
         if(isCurrent() == true)
         {
            curretNumber++;
         }  
      }
      catch(IllegalStateException E)
      {
         System.out.println("ERROR: There is no current element.");
      }
   }

   /**
   * Generate a copy of this sequence.
   * @return The return value is a copy of this sequence. Subsequent changes to the copy will not affect the original, nor vice versa. The return value must be typecast to a DoubleArraySeq before it is used.
   * @exception OutOfMemoryError Indicates insufficient memory for creating a clone.
   **/ 
   
   public DoubleArraySeq clone()
   {
      DoubleArraySeq answer;
      
      try
      {
         answer = (DoubleArraySeq) super.clone();
      }
      catch (CloneNotSupportedException e)
      {
         throw new RuntimeException
         ("This class does not implement Cloneable");
      }
      
      answer.data = data.clone();
      
      return answer;
   }
 
   /**
   * Create a new sequence that contains all the elements from one sequence followed by another.
   * @param s1 - the first of two sequences 
   * @param s2 - the seconds of two sequences
   * @precondition Neither s1 nor s2 is null.
   * @return A new sequence that has the elements of s1 followed by the elements of s2(with no current element)
   * @exception NullPointerException Indicates that one of the arguments is null.
   * @exception OutOfMemoryError Indicates insufficient memory for the new sequence.
   * @note An attempt to increase the capacity beyond Integer. MAX_VALUE will cause this sequence to fail with an arithmetic overflow.
   **/   

   public static DoubleArraySeq catenation(DoubleArraySeq s1, DoubleArraySeq s2)
   {
      try
      {
         if(s1 != null && s2 != null)
         {
            DoubleArraySeq combo = new DoubleArraySeq(s1.size() + s2.size());
            System.arraycopy(s1, 0, combo, 0, s2.size());
            System.arraycopy(s2, 0, combo, s1.size(), s2.size());
            return combo;
         }
      }
      catch(OutOfMemoryError E)
      {
         System.out.println("ERROR: System out of memory.");
      }
      catch(NullPointerException E)
      {
         System.out.println("ERROR: Array is null");
      }
      return null;
   }

   /**
   * Change the current capacity of this sequence
   * @param minimumCapacity – the new capacity for this sequence 
   * @postcondition  This sequence’s capacity has been changed to at least minimumCapacity.
   * @exception Indicates insufficient memory for new double[minimumCapacity].
   **/

   public void ensureCapacity(int minimumCapacity)
   {
      try
      {
         double[] resize;
         resize = new double[minimumCapacity];
         System.arraycopy(this.data, 0, resize, 0, minimumCapacity);
         this.data = resize;
      }
      catch(OutOfMemoryError E)
      {
         System.out.println("ERROR: System out of memory.");
      }
   }

   /**
   * Accessor method to determine the current capacity of this sequence. The addBefore and addAfter methods efficiently (without needing more memory) until this capacity is reached. 
   * @return The current capacity of the sequence.
   **/

   public int getCapacity( )
   {
      return this.data.length;
   }

   /**
   * Accessor method to get the current element of this sequence. 
   * @precondition isCurrent() returns true.
   * @return the current element of this sequence
   * @exception IllegalStateException Indicates that there is no current element.
   **/

   public double getCurrent( )
   {
      try
      {
         return this.data[curretNumber];
      }
      catch(IllegalStateException E)
      {
         System.out.println("ERROR: There is no current element.");
         return 0;
      }
   }

   /**
   * Accessor method to determine whether this sequence has a specified current element that can be retrieved with getCurrent method.
   * @return true (there is a current element) or false (there is no current element at the moment)
   **/

   public boolean isCurrent( )
   {
      try
      {
         if(curretNumber != 0)
         {
            return true;
         }
      }
      catch(IllegalStateException E)
      {
         System.out.println("ERROR: There is no current element.");
         return false;
      }
      return false;
   }
              
   /**
   * Remove the current element from this sequence.
   * @precondition isCurrent() returns true.
   * @postcondition The current element has been removed from this sequence, and the following element (if there is one) is now current element. If there was no following element, then there is now no current element.
   * @exception IllegalStateException Indicates that there is no current element, so removeCurrent may not be called.
   **/

   public void removeCurrent( )
   {
      try
      {
         if(isCurrent() == true)
         {
            this.data[curretNumber] = 0;
         }
      }
      catch(IllegalStateException E)
      {
         System.out.println("ERROR: There is no current element.");
      }

   }

   /**
   * Accessor method to determine the number of element in this sequence.
   * @return The number of elements of this sequence
   **/ 
                 
   public int size( )
   {
      return this.data.length;
   }
   
   /**
   * Set the current element at the front of this sequence 
   * @postcondition The front element of this sequence is now the current element (but if this sequence has no elements at all, then there is no current element)
   **/ 
   
   public void start( )
   {
      this.curretNumber = 0;
   }
   
   /**
   * Reduce the current capacity of this sequence to its actual size (i.e., the number of elements its contains).
   * @postcondition This sequence’s capacity has been to its current size.
   * @exception OutOfMemoryError Indicates insufficient memory for altering the capacity
   **/

   public void trimToSize( )
   {
      try
      {
         double[] trimmedArray;
         
         if(this.data.length != manyItems)
         {
            trimmedArray = new double[manyItems];
            System.arraycopy(data, 0, trimmedArray, 0, manyItems);
            data = trimmedArray;
         }
      }
      catch(OutOfMemoryError E)
      {
         System.out.println("ERROR: System out of memory.");
      }
   }
      
}
           
