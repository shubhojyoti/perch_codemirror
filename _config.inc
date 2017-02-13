
    <link rel="stylesheet" href="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/lib/codemirror.min.css">
    <link rel="stylesheet" href="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/addon/hint/show-hint.min.css">
    <link rel="stylesheet" href="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/theme/eclipse.min.css">
    <script src="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/lib/codemirror.min.js"></script>
    <script src="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/addon/hint/show-hint.min.js"></script>
    <script src="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/addon/hint/xml-hint.min.js"></script>
    <script src="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/addon/hint/css-hint.min.js"></script>
    <script src="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/addon/hint/html-hint.min.js"></script>
    <script src="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/addon/edit/continuelist.min.js"></script>
    <script src="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/mode/css/css.min.js"></script>
    <script src="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/mode/javascript/javascript.min.js"></script>
    <script src="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/mode/xml/xml.min.js"></script>
    <script src="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/mode/htmlmixed/htmlmixed.min.js"></script>
    <script src="PERCH_LOGINPATH/addons/plugins/editors/codemirror/codemirror/mode/markdown/markdown.min.js"></script>
    <script type="text/javascript">
        $(document).ready(function() {
            var tarea = {};
            var set_up_codemirror = function() {
                $('textarea.codemirror:not([data-init])').attr('data-init', true).each(function(i, o) {
                    tarea = o;
                    foreachtarea(tarea);
                });

                function completeAfter(cm, pred) {
                    var cur = cm.getCursor();
                    if (!pred || pred()) setTimeout(function() {
                        if (!cm.state.completionActive)
                        cm.showHint({completeSingle: false});
                    }, 100);
                    return CodeMirror.Pass;
                }

                function completeIfAfterLt(cm) {
                    return completeAfter(cm, function() {
                        var cur = cm.getCursor();
                        return cm.getRange(CodeMirror.Pos(cur.line, cur.ch - 1), cur) == "<";
                    });
                }

                function completeIfInTag(cm) {
                    return completeAfter(cm, function() {
                        var tok = cm.getTokenAt(cm.getCursor());
                        if (tok.type == "string" && (!/['"]/.test(tok.string.charAt(tok.string.length - 1)) || tok.string.length == 1)) return false;
                        var inner = CodeMirror.innerMode(cm.getMode(), tok.state).state;
                        return inner.tagName;
                    });
                }

                // add codemirror to textarea
                function foreachtarea(o) {
                    var editMode = o.getAttribute("data-editor-config") || null;
                    if (editMode !== null && editMode === "markdown") {
                        editMode = "markdown";
                    } else {
                        editMode = "text/html";
                    }
                    var editor = CodeMirror.fromTextArea(tarea, {
                        mode: editMode,
                        autoCloseTags: true,
                        lineNumbers: false,
                        lineWrapping: true,
                        extraKeys: {
                            "'<'": completeAfter,
                            "'/'": completeIfAfterLt,
                            "' '": completeIfInTag,
                            "'='": completeIfInTag
                        },
                        indentUnit: 4,
                        smartIndent: true,
                        tabSize: 4,
                        indentWithTabs: false,
                        theme: "eclipse"
                    });
                }
            };

            set_up_codemirror();

            $(window).on('Perch_Init_Editors', function() {
                set_up_codemirror();
            });
        });
    </script>
