#
# @lc app=leetcode.cn id=811 lang=python3
#
# [811] 子域名访问计数
#
from typing import *
import collections
# @lc code=start
class Solution:
    def subdomainVisits(self, cpdomains: List[str]) -> List[str]:
        counter = collections.Counter()
        for line in cpdomains:
            count, domain = line.split()
            count = int(count)
            domain = domain.split('.')
            for i in range(len(domain)):
                visit_domain = '.'.join(domain[i:])
                counter[visit_domain] += count
        return [f"{count} {domain}" for domain, count in counter.items()]
# @lc code=end

