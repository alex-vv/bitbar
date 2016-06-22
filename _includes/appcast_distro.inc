<?xml version="1.0" encoding="utf-8"?>
<rss version="2.0" xmlns:sparkle="http://www.andymatuschak.org/xml-namespaces/sparkle" xmlns:dc="http://purl.org/dc/elements/1.1/">
    <channel>
        <title>{{ site.github.project_title }}</title>
        <description>Most recent changes with links to updates.</description>
        <language>en</language>
        {% for release in site.github.releases %}
            {% unless release.draft %}
                {% unless release.prerelease and page.release_only %}
                    <item>
                        <title>{{ release.name }}</title>
                        <description><![CDATA[{% assign links = release.body | markdownify | split:'<a href="' %}{{ links[0] }}{% for link in links offset:1 %}<a href="{% assign href = link | split:'">' | first %}{% unless href contains '://' %}https://github.com/matryer/bitbar/blob/{{ release.tag_name }}/{% endunless %}{{ link }}{% endfor %}]]></description>
                        <pubDate>{{ release.published_at | date_to_rfc822 }}</pubDate>
                        {% for asset in release.assets limit:1 offset:1 %}
                            <enclosure
                                url="{{ asset.browser_download_url }}"
                                sparkle:version="{{ release.tag_name | remove_first:'v' }}"
                                length="{{ asset.size }}"
                                type="application/octet-stream" />
                        {% endfor %}
                    </item>
                {% endunless %}
            {% endunless %}
        {% endfor %}
    </channel>
</rss>