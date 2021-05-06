#!/usr/bin/python3
"""Count it!"""
from requests import get


REDDIT = "https://www.reddit.com/"
HEADERS = {'user-agent': 'my-app/0.0.1'}


def count_words(subreddit, word_list, after="", word_dict={}):
    """Recursive function that queries the Reddit API"""
    if not word_dict:
        for word in word_list:
            word_dict[word] = 0
    if after is None:
        word_list = [[key, value] for key, value in word_dict.items()]
        word_list = sorted(word_list, key=lambda x: (-x[1], x[0]))
        for w in word_list:
            if w[1]:
                print("{}: {}".format(w[0].lower(), w[1]))
        return None
    url = REDDIT + "r/{}/hot/.json".format(subreddit)
    param = {'limit': 100, 'after': after}
    r = get(url, headers=HEADERS, params=param, allow_redirects=False)
    if r.status_code != 200:
        return None
    try:
        js = r.json()
    except ValueError:
        return None
    try:
        data = js.get("data")
        after = data.get("after")
        childs = data.get("children")
        for child in childs:
            post = child.get("data")
            title = post.get("title")
            lower = [s.lower() for s in title.split(' ')]
            for w in word_list:
                word_dict[w] += lower.count(w.lower())
    except Exception:
        return None

    count_words(subreddit, word_list, after, word_dict)
