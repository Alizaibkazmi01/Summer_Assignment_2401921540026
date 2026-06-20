class MyQueue {
public:

    //Amortized O(1) : refers to a time complexity analysis where the average time per operation is constant, even though some operations may take longer like O(N).

    stack<int> input ;
    stack<int> output ;

    int peekele = -1  ; // for storing the peek elemet 



    MyQueue() {
        
    }
    
    void push(int x) {
        

        if( input.empty() ){
            peekele = x ; 
        }
        input.push( x ) ; 
        
    }
    
    int pop() {

        if( output.empty() ){
            // put all from input to output stack -> O(N)

            while( !input.empty() ){
                output.push( input.top() ) ;
                input.pop() ; 
            }

        }
        int value = output.top() ; // AMORTISED O(1)
        output.pop() ; 
        
        return value ; 
        
    }
    
    int peek() {

        if( output.empty() ){// if output is empty
            
            return peekele  ; // return the peekele already stored
        }

        return output.top() ; // else return the top of output
        
    }
    
    bool empty() {

        if( input.empty() && output.empty() ){
            return true ; 
        }

        return false ; 
        
    }
};
