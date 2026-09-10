class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        maxdiagonal = 0
        answer = 0
        for i in range(len(dimensions)):
            length = dimensions[i][1]
            width =dimensions[i][0]
            diagonal  = math.sqrt(length*length + width * width)
            area = length * width 
            if(diagonal > maxdiagonal):
                maxdiagonal = diagonal 
                answer = area
             
            elif diagonal == maxdiagonal:
                answer = max(answer, area)   

        return answer       