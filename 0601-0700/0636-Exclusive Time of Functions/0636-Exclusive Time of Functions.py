class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        time = [0] * n
        prev = 0
        St = []
        for log in logs:
            fid, start, timestamp = log.split(':')
            fid = int(fid)
            timestamp = int(timestamp)
            if start == 'start':
                if St:
                    time[St[-1]] += timestamp - prev
                St.append(fid)
                prev = timestamp
            else:
                time[St.pop()] += timestamp - prev + 1
                prev = timestamp + 1
        return time
