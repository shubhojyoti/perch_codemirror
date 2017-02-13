perch codemirror editor plugin
===============================

This is a [Code Mirror](https://codemirror.net) editor plugin for [Perch CMS](https://grabaperch.com). HTML syntax and Markdown is supported.

Codemirror version used = 5.23.0
Perch version tested on = 2.8.34

### Requirements

There are no extra additions required in your Perch CMS installation.

### Installation

 1. Clone or download and unzip the repository to your system.
 2. Copy the "codemirror" folder to your *PERCH_INSTALLATION_PATH/perch/addons/plugins/editors/* directory.

### Usage

 1. Update your perch templates to enable codemirror on a HTML textarea as follows:
      ```
      <perch:blog id="someHtmlTextArea" type="textarea" editor="codemirror" html="true" label="My HTML Area" />
      ```

 2. Update your perch templates to enable codemirror on a markdown as follows:
      ```
      <perch:blog id="someMarkDownTextArea" type="textarea" editor="codemirror" markdown="true" label="My Markdown Area" />
      ```

### Screenshots

**HTML Textarea in backend (syntax highlight and autocompletion)**

![HTML Screenshot](https://cloud.githubusercontent.com/assets/7550811/22895336/1c44f17c-f242-11e6-8455-7bac6cacd2d5.png)

**Markdown Textarea in backend**

![Markdown Screenshot](https://cloud.githubusercontent.com/assets/7550811/22895372/36a59594-f242-11e6-98e0-bae897621edf.png)

### Extend the plugin

* You can add other addons from the official codemirror repository as well as themes.
* This repo only contains the stripped out and minified addons, modes and other files from codemirror. I have removed all other language modes and addons as it is not supported by default.
* For extending the plugin:
    1. Copy the extra addons, modes, themes, etc. from official codemirror site.
    2. Update the _config.inc file in this repo with the path to the additions JS/CSS files.
    3. Update the CodeMirror instance call with your new options.


### Acknowledgements

1. [Codemirror Project](https://codemirror.net)
2. [Perch CMS](https://grabaperch.com)
3. [Forum post by Ronan Doherty](http://forum.grabaperch.com/forum/10-27-2015-issue-adding-codemirror-text-editor-to-perch)
