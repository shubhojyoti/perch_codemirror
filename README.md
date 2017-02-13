perch codemirror editor plugin
===============================

This is a [Code Mirror](https://codemirror.net) editor plugin for [Perch CMS](https://grabaperch.com). HTML syntax and Markdown is supported.

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

**HTML Textarea in backend**


**Markdown Textarea in backend**


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
