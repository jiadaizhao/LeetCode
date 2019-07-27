class Solution:
    def smallestSufficientTeam(self, req_skills: List[str], people: List[List[str]]) -> List[int]:
        table = {skill : (1 << i) for i, skill in enumerate(req_skills)}
        dp = {0 : []}
        for i, p in enumerate(people):
            curr = 0
            for s in p:
                if s in table:
                    curr |= table[s]

            for skills, team in list(dp.items()):
                newSkills = skills | curr
                if newSkills != skills:
                    if newSkills not in dp or len(dp[newSkills]) > len(team) + 1:
                        dp[newSkills] = team + [i]
        
        return dp[(1 << len(req_skills)) - 1]
