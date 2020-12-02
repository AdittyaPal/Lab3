public class HighwayAdvertisment
{
    public int maxRevenue(int ad[], int revenue[], int distance, int restrict) 
    {
        intmaxRevenue[] = new int[distance + 1];
        maxRevenue[0] = 0;
        for (int i = 1; i <= distance; i++) {
            if(ad[i]!=1)
            {
                maxRevenue[i] = maxRevenue[i - 1];
            }
            else 
            {                    
                if(i>=restrict)
                {
                    maxRevenue[i] = Math.max(maxRevenue[i-restrict]+revenue[i], maxRevenue[i-1]);
                }
                else
                {
                    maxRevenue[i]=Math.max(revenue[i], maxRevenue[i-1]);
                    }

                    nextBillBoard++;
                }
            }
        }
        return maxRevenue[distance];
    }
    public static void main(String[] args) 
    {
        int x[] = {0,0,0,0,0,1,1,0,0,0,0,1,1,1,0,0,0,0,0,0};//1 if advertisment allowed for that km else 0
        int revenue[] = {0,0,0,0,0,5,6,0,0,0,0,5,3,1,0,0,0,0,0,0};//if ad [resent, revenue of ad else 0
        int distance = 20;
        int distanceRestriction = 5;
        HighwayAdvertisment obj1 = new HighwayAdvertisment();
        int result = obj1.maxRevenue(x, revenue, distance, distanceRestriction);
        System.out.println("Maximum revenue that can be generated :" + result);
    }
}
