int minJumps(int arr[], int n){
        // Your code here
        if(arr[0]==0) return -1;
        int steps=arr[0];
        int maxReach=arr[0];
        int jump=1;

        for(int i=1;i<n-1;i++){
            steps--;
            maxReach=max(maxReach , arr[i] + i);  //harr step pe check kr rhe ki ab iske baad max kaha tkk jaa payge 
            //kind of max element pick krna...aur i isliye add kr rhe kuku jaha khde hue hai waha se count lena hoga
        
            
            if(steps==0){
                jump++;
                steps=maxReach-i;   // ye isliye ki jo bich se saare elements se max jaa skte thee....
                // agr wo aur curr index same hue to kahi nhi jaa payge..ya maxReach curr index se kam hua to bhi
                if(steps<=0) return -1;    //agr steps update krne ke baad bhi steps 0 ya kam hue to aage badega nhi
            }
        }
        return jump;
    }
